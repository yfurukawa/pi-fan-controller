#include <csignal>
#include <iostream>
#include <memory>
#include <string>
#include <syslog.h>
#include "FanController.h"
#include "Gpio.h"
#include "IGpioPin.h"
#include "DigitalOut.h"

/*
* CPU温度のチェック間隔
*
* 10秒ごとに温度を確認する。
*/
#define CHECK_INTERVAL 10

volatile std::sig_atomic_t running = 1;

void signal_handler(int sig)
{
    running = 0;
}

int main(int argc, char* argv[])
{
  if( argc != 4 ) {
    std::cout << "Usage:" << std::endl;
    std::cout << "  pi-fan-controlle lowerLimitTemperature uppeLimitTemperature fanInterfaceBCMNumber" << std::endl;
    exit(1);
  }

  double lowerLimit( std::stod( argv[1] ) );
  double upperLimit( std::stod( argv[2] ) );
  int  interfacePin( std::stoi( argv[3] ) );

  if( lowerLimit >= upperLimit )
  {
    std::cout << "lowerLimit must be smaller than upperLimit" << std::endl;
    exit(1);
  }

  /*
  * syslogを使用する。
  */
  openlog( "pi-fan-controller", LOG_PID | LOG_CONS, LOG_DAEMON);
  syslog( LOG_INFO, "Pi fan controller started" );
  
  /*
  * SIGTERM: systemd stop時に送られる。
  */
  signal( SIGTERM, signal_handler );

  /*
  * Ctrl+C対応
  */
  signal( SIGINT, signal_handler );


  Gpio* gpio = new Gpio();
  gpio->addPin( interfacePin, std::make_shared<DigitalOut>( "fanInterface", interfacePin ) );

  std::unique_ptr<FanController> fanController = std::make_unique<FanController>(lowerLimit, upperLimit, std::dynamic_pointer_cast<DigitalOut>( gpio->pin(interfacePin) ) );

  while( running )
  {
    fanController->controlFan();

    /*
    * 10秒待機する。
    *
    * 1秒ずつsleepすることで、SIGTERMを受け取ったときに比較的速く終了できる。
    */
    for (int i = 0; i < CHECK_INTERVAL && running; ++i)
    {
        sleep(1);
    }
  }
  
  /*
  auto fan = std::dynamic_pointer_cast<DigitalOut>( gpio->pin(interfacePin) );

  if (!fan) {
      exit(1);
  }
//  fanController->outputHigh();
  delay( 5000 );
  fan->outputLow();
  */
  
  closelog();
  delete gpio;

  return 0;
}

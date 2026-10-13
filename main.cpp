#include <iostream>
#include <memory>
#include <string>
#include "FanController.h"
#include "Gpio.h"
#include "IGpioPin.h"
#include "DigitalOut.h"

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

  Gpio* gpio = new Gpio();
  gpio->addPin( interfacePin, std::make_shared<DigitalOut>( "fanInterface", interfacePin ) );

  std::unique_ptr<FanController> fanController = std::make_unique<FanController>(lowerLimit, upperLimit, std::dynamic_pointer_cast<DigitalOut>( gpio->pin(interfacePin) ) );
  
  fanController->controlFan();

  auto fan = std::dynamic_pointer_cast<DigitalOut>( gpio->pin(interfacePin) );

  if (!fan) {
      exit(1);
  }
//  fanController->outputHigh();
  delay( 5000 );
  fan->outputLow();
  delete gpio;

  return 0;
}

#include <memory>
#include <string>
#include "FanController.h"
#include "Gpio.h"
#include "IGpioPin.h"
#include "DigitalOut.h"

int main(int argc, char* argv[])
{
  Gpio* gpio = new Gpio();
  gpio->addPin( 26, std::make_shared<DigitalOut>( "fanInterface", 26 ) );

  std::unique_ptr<FanController> fanController = std::make_unique<FanController>(30.0, 35.0, std::dynamic_pointer_cast<DigitalOut>( gpio->pin(26) ) );
  
  fanController->controlFan();

  auto fan = std::dynamic_pointer_cast<DigitalOut>( gpio->pin(26) );

  if (!fan) {
      exit(1);
  }
//  fanController->outputHigh();
  delay( 5000 );
  fan->outputLow();
  delete gpio;

  return 0;
}

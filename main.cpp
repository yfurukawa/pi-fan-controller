#include <memory>
#include <string>
#include "Gpio.h"
#include "IGpioPin.h"
#include "DigitalIO.h"

int main(int argc, char* argv[])
{
  Gpio* gpio = new Gpio();
  gpio->addPin( 26, std::make_shared<DigitalIO>( "fanController", 26 ) );

  auto fanController = std::dynamic_pointer_cast<DigitalIO>( gpio.pin(26) );

  if (!fanController) {
      exit(1);
  }
  fanController->outputHigh();
  delay( 5000 );
  fanController->outputLow();

  delete gpio;

  return 0;
}

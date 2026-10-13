#include <memory>
#include <string>
#include "Gpio.h"
#include "IGpioPin.h"
#include "DigitalIO.h"

int main(int argc, char* argv[])
{
  Gpio* gpio = new Gpio();
  gpio->addPin( 26, std::make_shared<DigitalIO>( "fanController", 26 ) );

  dynamic_cast<DigitalIO>(gpio->pin(26))->setMode( OUTPUT );
  //gpio->pin(26)->outputHigh();
  delay( 5000 );
  //gpio->pin(26)->outputLow();

  delete gpio;

  return 0;
}

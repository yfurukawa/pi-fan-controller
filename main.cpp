#include <string>
#include "Gpio.h"
#include "IGpioPin.h"
#include "DigitalIO.h"

int main(int argc, char* argv[])
{
  Gpio* gpio = new Gpio();
  gpio->addPin( new DigitalIO( "fanController", 26 ) );
  gpio->pin(26)->setMode( OUTPUT );
  gpio->pin(26)->outputHigh();
  delay( 5000 );
  gpio->pin(26)->outputLow();

  delete gpio;

  return 0;
}
#include "Gpio.h"

int main(int argc, char* argv[])
{
  Gpio* fanController = new Gpio( "fanController", 26 );
  fanController->setMode( OUTPUT );
  fanController->outputHigh();
  delay( 5000 );
  fanController->outputLow();

  delete fanController;

  return 0;
}
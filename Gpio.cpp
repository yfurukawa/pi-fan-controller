//#include <memory>
#include <wiringPi.h>
#include "Gpio.h"

Gpio::Gpio()
{
  wiringPiSetupPinType(WPI_PIN_BCM);
}

Gpio::~Gpio()
{
  for( auto itr = gpioPins.begin(); itr != gpioPins.end(); ++itr )
  {
    gpioPins.erase(itr);
  }
}

bool Gpio::addPin(int bcmNumber, IGpioPin* pin)
{
  auto itr = gpioPins.insert( std::make_pair(bcmNumber, std::make_unique<IGpioPin*>(pin)) );
  // insert時にキーが重複していた場合、そのデータへのイテレータが返る
  if( 1 )
  {
    return false;
  }
  else
  {
    return true;
  }
}

std::unique_ptr<IGpioPin*> Gpio::pin(int pin)
{
  return gpioPins[pin];
}

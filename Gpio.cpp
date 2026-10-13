#include <wiringPi.h>
#include "Gpio.h"

Gpio::Gpio()
{
  wiringPiSetupPinType(WPI_PIN_BCM);
}

Gpio::~Gpio()
{

}

bool Gpio::addPin(int bcmNumber, IGpioPin* pin)
{
  auto itr = gpioPins.insert( std::make_pair(bcmNumber, pin) );
  // insert時にキーが重複していた場合、そのデータへのイテレータが返る
  if( itr == NULL )
  {
    return true;
  }
  else
  {
    return false;
  }
}

IGpioPin* Gpio::pin(int pin)
{

}

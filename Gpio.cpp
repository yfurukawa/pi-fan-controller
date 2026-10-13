#include <utility>
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

bool Gpio::addPin(int bcmNumber, std::shared_ptr<IGpioPin> pin)
{
  if( !pin )
  {
    return false;
  }

  auto [it, inserted] = gpioPins.try_emplace(bcmNumber, std::move(pin));
  return inserted;
}

std::shared_ptr<IGpioPin> Gpio::pin(const int bcmNumber)
{
  return gpioPins.at( bcmNumber );
}

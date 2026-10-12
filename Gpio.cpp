#include "Gpio.h"

Gpio::Gpio()
{
  wiringPiSetupPinType(WPI_PIN_BCM);
}

Gpio::~Gpio()
{

}

bool Gpio::addPin(IGpioPin pin)
{

}

IGpioPin Gpio::providePin(std::string name, IGpioPin* pin)
{

}

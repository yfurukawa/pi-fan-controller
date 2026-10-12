#include "Gpio.h"

Gpio::Gpio()
{
  wiringPiSetupPinType(WPI_PIN_BCM);
}

Gpio::~Gpio()
{

}

bool Gpio::addPin(int bcmNumber, IGpioPin*)
{

}

IGpioPin* Gpio::pin(int pin)
{

}

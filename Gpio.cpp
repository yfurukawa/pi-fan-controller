#include "Gpio.h"

Gpio::Gpio(std::string name, int bcmNumber) : name_(name), bcmNumber_(bcmNumber)
{
    // Raspberry PiのGPIOのBCM番号は、2から27の範囲なので範囲内にあることを保証する
    if( bcmNumber_ < 2 ) {
        bcmNumber_ = 2;
    }
    if( bcmNumber_ > 27 ) {
        bcmNumber_ = 27;
    }
    wiringPiSetupPinType(WPI_PIN_BCM);
}

Gpio::~Gpio()
{
    this->setMode( PM_OFF );
}

void Gpio::setMode( int mode )
{
    pinMode( bcmNumber_, mode );
}

void Gpio::outputHigh()
{
    digitalWrite( bcmNumber_, HIGH );
}

void Gpio::outputLow()
{
    digitalWrite( bcmNumber_, LOW );
}

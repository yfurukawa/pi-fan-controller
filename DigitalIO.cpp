#include "DigitalIO.h"

DigitalIO::DigitalIO(const std::string name, const int bcmNumber) : IGpioPin( name, bcmNumber )
{
    // Raspberry PiのGPIOのBCM番号は、2から27の範囲なので範囲内にあることを保証する
    if( bcmNumber_ < 2 ) {
        bcmNumber_ = 2;
    }
    if( bcmNumber_ > 27 ) {
        bcmNumber_ = 27;
    }
}

DigitalIO::~DigitalIO()
{
    this->setMode( PM_OFF );
}

void DigitalIO::shutdown()
{
    pinMode( bcmNumber_, PM_OFF );
}

void DigitalIO::setMode( int mode )
{
    pinMode( bcmNumber_, mode );
}

void DigitalIO::outputHigh()
{
    digitalWrite( bcmNumber_, HIGH );
}

void DigitalIO::outputLow()
{
    digitalWrite( bcmNumber_, LOW );
}

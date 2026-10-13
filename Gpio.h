#ifndef GPIO_H_
#define GPIO_H_

#include <string>
#include <map>
#include <memory>
#include "IGpioPin.h"

class Gpio
{
public:
  Gpio();
  virtual ~Gpio();
  bool addPin(int bcmNumber, std::unique_ptr<IGpioPin*>* pin);
  std::unique_ptr<IGpioPin*> pin(int bcmNumber);

protected:
  std::map<int, std::unique_ptr<IGpioPin*>*> gpioPins;  //!< 入出力用に設定されたGPIO Pin
};

#endif


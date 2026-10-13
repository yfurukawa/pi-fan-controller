#ifndef IGPIOPIN_H_
#define IGPIOPIN_H_

#include <string>

class IGpioPin
{
public:
  IGpioPin(const std::string& name, const int& bcmNumber){};
  virtual ~IGpioPin() = default;

protected:
  std::string name_;  //!< GPIOの用途
  int bcmNumber_;     //!< 制御するGPIOのBCM番号

  IGpioPin(){};
};

#endif


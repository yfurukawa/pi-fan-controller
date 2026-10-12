#include <string>
#include <map>
#include "IGpioPin.h"

class Gpio
{
public:
  Gpio();
  virtual ~Gpio();
  bool addPin(IGpioPin pin);
  IGpioPin providePin(std::string name, IGpioPin* pin);

protected:
  std::map<std::string, IGpioPin*> gpioPins;  //!< 入出力用に設定されたGPIO Pin
}
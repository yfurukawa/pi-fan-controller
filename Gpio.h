#include <string>
#include <map>
#include "IGpioPin.h"

class Gpio
{
public:
  Gpio();
  virtual ~Gpio();
  bool addPin(int bcmNumber, IGpioPin* pin);
  IGpioPin* pin(int bcmNumber);

protected:
  std::map<int, IGpioPin*> gpioPins;  //!< 入出力用に設定されたGPIO Pin
};

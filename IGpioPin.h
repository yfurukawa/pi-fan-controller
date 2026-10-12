#include <string>

class IGpioPin
{
public:
  IGpioPin(const std::string name, const int bcmNumber);
  virtual ~IGpioPin();
  virtual void shutdown() = 0;

protected:
  std::string name_;  //!< GPIOの用途
  int bcmNumber_;     //!< 制御するGPIOのBCM番号

private:
  IGpioPin();
};

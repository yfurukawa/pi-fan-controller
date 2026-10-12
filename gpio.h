#include <wiringPi.h>

class gpio
{
public:
    gpio(std::string name, int bcmNumber);
    ~gpio();
    void setMode()
private:
    gpio();
    std::string name_;
    int bcmNumber_;
};

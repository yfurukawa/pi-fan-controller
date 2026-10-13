#include "FanController.h"

FanController::FanController( double lowerLimit, double upperLimit, std::shared_ptr<DigitalOut> fanInterfacePin ):lowerLimit_(lowerLimit), upperLimit_(upperLimit), fanInterfacePin_(fanInterfacePin)
{
  if( lowerLimit_ <= 25.0 )
  {
    lowerLimit_ = 25.0;
  }
  if( upperLimit_ >= 70.0 )
  {
    upperLimit_ = 70.0;
  }

  cpuTemp_ = std::make_unique<CpuTemperatureMonitor>();
}

FanController::~FanController()
{

}

void FanController::controlFan()
{

}

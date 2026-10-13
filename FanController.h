#ifndef FANCONTROLLER_H_
#define FANCONTROLLER_H_

#include <memory>
#include "CpuTemperatureMonitor.h"
#include "DigitalOut.h"

class FanController
{
public:
  FanController( double lowerLimit, double upperLimit, std::shared_ptr<DigitalOut> fanInterfacePin );
  virtual ~FanController();
  void controlFan();

private:
  double lowerLimit_;   //!< it is not necessary to cooling temperature
  double upperLimit_;   //!< it is necessary to cooling temperature
  std::shared_ptr<DigitalOut> fanInterfacePin_;     //!< this pin controls fan on/off
  std::unique_ptr<CpuTemperatureMonitor> cpuTemp_;  //!< cpu temperature monitor

  FanController() = default;
};

#endif

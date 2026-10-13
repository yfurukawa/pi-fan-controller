#ifndef CPUTEMPERATIREMONITOR_H_
#define CPUTEMPERATIREMONITOR_H_

class CpuTemperatureMonitor
{
public:
  CpuTemperatureMonitor();
  virtual ~CpuTemperatureMonitor();
  double readCpuTemp();
  
private:

};

#endif

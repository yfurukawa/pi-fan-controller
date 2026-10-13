#include <fstream>
#include "CpuTemperatureMonitor.h"

CpuTemperatureMonitor::CpuTemperatureMonitor()
{

}

CpuTemperatureMonitor::~CpuTemperatureMonitor()
{

}

double CpuTemperatureMonitor::readCpuTemp()
{
  std::ifstream file("/sys/class/thermal/thermal_zone0/temp");

  if (!file) {
      return -1.0;
  }

  long temp = 0;

  if (!(file >> temp)) {
      return -1.0;
  }

  // 温度は1000倍されているため、摂氏に変換
  return static_cast<double>(temp) / 1000.0;
}

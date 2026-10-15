/*! @file CpuTemperatureMonitor.h
 *  @brief Header file for the CpuTemperatureMonitor class
 *  @details
  *  CPU温度を取得するクラス
  *  Raspberry Piの/sys/class/thermal/thermal_zone0/tempにあるCPU温度を取得し、
  *  摂氏に変換する。
  *  動作確認OSは、Ubuntu 64bit
 */
#ifndef CPUTEMPERATIREMONITOR_H_
#define CPUTEMPERATIREMONITOR_H_

class CpuTemperatureMonitor
{
public:
  /*!
   * @brief Constructor for CpuTemperatureMonitor
   */
  CpuTemperatureMonitor();

  /*!
   * @brief Destructor for CpuTemperatureMonitor
   */
  virtual ~CpuTemperatureMonitor();

  /*!
   * @brief Reads the CPU temperature
   * @return The CPU temperature in Celsius
   */
  double readCpuTemp();

private:

};

#endif

/*! @file FanController.h
 *  @brief Header file for the FanController class
 *  @details
 *  ファンを制御するクラス
 *  CPU温度に基づいてファンのON/OFFを制御する。
 *  動作確認OSは、Ubuntu 64bit
 */
#ifndef FANCONTROLLER_H_
#define FANCONTROLLER_H_

#include <memory>
#include "CpuTemperatureMonitor.h"
#include "DigitalOut.h"

class FanController
{
public:
  /*!
   * @brief Constructor for FanController
   * @param lowerLimit The temperature below which the fan will be turned off
   * @param upperLimit The temperature above which the fan will be turned on
   * @param fanInterfacePin The pin used to control the fan
   */
  FanController( double lowerLimit, double upperLimit, std::shared_ptr<DigitalOut> fanInterfacePin );
  /*!
   * @brief Destructor for FanController
   *
   */
  virtual ~FanController();
  /*!
   * @brief Controls the fan based on the CPU temperature
   * @details
   * This function reads the CPU temperature and turns the fan on or off based on the specified lower and upper limits.
   * If the CPU temperature is below the lower limit, the fan will be turned off.
   * If the CPU temperature is above the upper limit, the fan will be turned on.
   * If the CPU temperature is between the lower and upper limits, the fan state will remain unchanged.
   */
  void controlFan();

private:
  double lowerLimit_;   //!< it is not necessary to cooling temperature
  double upperLimit_;   //!< it is necessary to cooling temperature
  std::shared_ptr<DigitalOut> fanInterfacePin_;     //!< this pin controls fan on/off
  std::unique_ptr<CpuTemperatureMonitor> cpuTemp_;  //!< cpu temperature monitor

  FanController() = default;
};

#endif

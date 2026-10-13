//! DigitalOut class
/*!
 * GPIOインターフェースが提供するデジタル出力を制御する
 * 引数で渡されたBCM番号のGPIOピンをデジタル出力にセットして出力を制御する
 * GPIOの制御にはwiringPi（https://github.com/WiringPi/WiringPi）を使用
 *
 */
#ifndef DIGITALOUT_H_
#define DIGITALOUT_H_

#include <string>
#include <wiringPi.h>
#include "IGpioPin.h"

class DigitalOut: public IGpioPin
{
public:
    //! コンストラクタ
    /*!
    \param name GPIOの用途
    \param bcmNumber GPIOの番号（2〜27）
    */
    DigitalOut(const std::string& name, const int& bcmNumber);

    //! デストラクタ
    virtual ~DigitalOut();

    //! ロジックレベルHighを出力する
    void outputHigh();

    //! ロジックレベルLowを出力する
    void outputLow();

private:
    DigitalOut(){};
};

#endif


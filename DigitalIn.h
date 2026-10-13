//! DigitalIn class
/*!
 * GPIOインターフェースが提供するデジタル入力を制御する
 * 引数で渡されたBCM番号のGPIOピンをデジタル入力にセットして入力値を読み取る
 * GPIOの制御にはwiringPi（https://github.com/WiringPi/WiringPi）を使用
 *
 */
#ifndef DIGITALIN_H_
#define DIGITALIN_H_

#include <string>
#include <wiringPi.h>
#include "IGpioPin.h"

class DigitalIn: public IGpioPin
{
public:
    //! コンストラクタ
    /*!
    \param name GPIOの用途
    \param bcmNumber GPIOの番号（2〜27）
    */
    DigitalIn(const std::string& name, const int& bcmNumber);

    //! デストラクタ
    virtual ~DigitalIn();

private:
    DigitalIn(){};
};

#endif


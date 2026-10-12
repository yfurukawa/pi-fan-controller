//! Gpio class
/*!
 * GPIOインターフェースを制御する
 * 引数で渡されたBCM番号のGPIOの入出力を制御する
 * GPIOの制御にはwiringPi（https://github.com/WiringPi/WiringPi）を使用
 *
 */

#include <string>
#include <wiringPi.h>

class Gpio
{
public:
	//! コンストラクタ
	/*!
	 \param name GPIOの用途
     \param bcmNumber GPIOの番号（2〜27）
	*/
    Gpio(std::string name, int bcmNumber);

    //! デストラクタ
    ~Gpio();

    //! 入出力モード設定
    /*!
    当該クラスが管理するピンの入出力モードを設定する
    \param mode 入出力モード
        INPUT ... Input
        OUTPUT ... Output
        PWM_OUTPUT ... PWM output (frequency and pulse break ratio can be configured)
        PWM_MS_OUTPUT ... PWM output with MS (Mark/Space)
        PWM_BAL_OUTPUT ... PWM output with mode balanced
        GPIO_CLOCK ... Frequency output
        PM_OFF ... Release
    */
    void setMode(int mode);

    //! ロジックレベルHighを出力する
    void outputHigh();

    //! ロジックレベルLowを出力する
    void outputLow();

private:
    gpio();
    std::string name_;  //!< GPIOの用途
    int bcmNumber_;     //!< 制御するGPIOのBCM番号
};

#include <config/parameter.h>
#include <config/pin.h>
#include <Arduino.h>

class ArmRobot
{
private:
public:
    ArmRobot()
    {
        pinMode(LimitSwitch_B_Down, INPUT_PULLUP);
        pinMode(LimitSwitch_B_Up, INPUT_PULLUP);
        pinMode(Switch_Blue, INPUT_PULLUP);
        pinMode(Switch_Red, INPUT_PULLUP);

        pinMode(M1_PWM, OUTPUT);
        pinMode(M1_IN1, OUTPUT);
        pinMode(M1_IN2, OUTPUT);

        pinMode(M2_PWM, OUTPUT);
        pinMode(M2_IN1, OUTPUT);
        pinMode(M2_IN2, OUTPUT);
    }
    void Init()
    {
        pinMode(LimitSwitch_B_Down, INPUT_PULLUP);
        pinMode(LimitSwitch_B_Up, INPUT_PULLUP);
        pinMode(Switch_Blue, INPUT_PULLUP);
        pinMode(Switch_Red, INPUT_PULLUP);

        pinMode(M1_PWM, OUTPUT);
        pinMode(M1_IN1, OUTPUT);
        pinMode(M1_IN2, OUTPUT);

        pinMode(M2_PWM, OUTPUT);
        pinMode(M2_IN1, OUTPUT);
        pinMode(M2_IN2, OUTPUT);
    }

    bool control(int UD)
    {
        if (UD == 0)
        {
            if (digitalRead(LimitSwitch_B_Down) == 0)
            {

                analogWrite(M2_PWM, 255);
                digitalWrite(M2_IN1, 1);
                digitalWrite(M2_IN2, 1);
                return false;
            }
            else
            {
                analogWrite(M2_PWM, 100);
                digitalWrite(M2_IN1, 1);
                digitalWrite(M2_IN2, 0);

                return true;
            }
        }
        else if (UD == 1)
        {
            if (digitalRead(LimitSwitch_B_Up) == 0)
            {
                analogWrite(M2_PWM, 255);
                digitalWrite(M2_IN1, 1);
                digitalWrite(M2_IN2, 1);

                return false;
            }
            else
            {
                analogWrite(M2_PWM, 255);
                digitalWrite(M2_IN1, 0);
                digitalWrite(M2_IN2, 1);

                return true;
            }
        }
    }
};

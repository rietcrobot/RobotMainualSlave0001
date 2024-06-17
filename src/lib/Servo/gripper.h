#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <config/parameter.h>
#include <config/pin.h>

#define SERVOMIN 150  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2400    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

class Gripper
{
private:
    Adafruit_PWMServoDriver pwm;

public:
    Gripper() : pwm(Adafruit_PWMServoDriver())
    {
    }

    void Init()
    {
        pwm.begin();
        pwm.setOscillatorFrequency(27000000);
        pwm.setPWMFreq(SERVO_FREQ);

        pwm.setPWM(Servo_1, 0, Servo1_MAX);
        pwm.setPWM(Servo_2, 0, Servo2_MAX);
        pwm.setPWM(Servo_3, 0, Servo3_MAX);
        pwm.setPWM(Servo_4, 0, Servo4_MAX);
        pwm.setPWM(Servo_5, 0, Servo5_MAX);
        pwm.setPWM(Servo_6, 0, Servo6_MAX);
        pwm.setPWM(Servo_7, 0, Servo7_MAX);
        pwm.setPWM(Servo_8, 0, Servo8_MAX);
    }

    void Get(int Gripper)
    {
        switch (Gripper)
        {
        case 1:
            pwm.setPWM(Servo_1, 0, Servo1_MIN);
            pwm.setPWM(Servo_2, 0, Servo2_MIN);
            // Add your code here for Gripper 1
            break;
        case 2:
            pwm.setPWM(Servo_3, 0, Servo3_MIN);
            pwm.setPWM(Servo_4, 0, Servo4_MIN);
            // Add your code here for Gripper 2
            break;
        case 3:
            pwm.setPWM(Servo_5, 0, Servo5_MIN);
            pwm.setPWM(Servo_6, 0, Servo6_MIN);
            // Add your code here for Gripper 3
            break;
        case 4:
            pwm.setPWM(Servo_7, 0, Servo7_MIN);
            pwm.setPWM(Servo_8, 0, Servo8_MIN);
            // Add your code here for Gripper 4
            break;
        case 0:
            pwm.setPWM(Servo_1, 0, Servo1_MIN);
            pwm.setPWM(Servo_2, 0, Servo2_MIN);

            pwm.setPWM(Servo_3, 0, Servo3_MIN);
            pwm.setPWM(Servo_4, 0, Servo4_MIN);

            pwm.setPWM(Servo_5, 0, Servo5_MIN);
            pwm.setPWM(Servo_6, 0, Servo6_MIN);

            pwm.setPWM(Servo_7, 0, Servo7_MIN);
            pwm.setPWM(Servo_8, 0, Servo8_MIN);
            // Add your code here for Gripper 4
            break;
        default:

            pwm.setPWM(Servo_1, 0, Servo1_MIN);
            pwm.setPWM(Servo_2, 0, Servo2_MIN);

            pwm.setPWM(Servo_3, 0, Servo3_MIN);
            pwm.setPWM(Servo_4, 0, Servo4_MIN);

            pwm.setPWM(Servo_5, 0, Servo5_MIN);
            pwm.setPWM(Servo_6, 0, Servo6_MIN);

            pwm.setPWM(Servo_7, 0, Servo7_MIN);
            pwm.setPWM(Servo_8, 0, Servo8_MIN);
            break;
        }
    }

    void Push(int Gripper)
    {
        switch (Gripper)
        {
        case 1:
            pwm.setPWM(Servo_1, 0, Servo1_MAX);
            pwm.setPWM(Servo_2, 0, Servo2_MAX);
            // Add your code here for Gripper 1
            break;
        case 2:
            pwm.setPWM(Servo_3, 0, Servo3_MAX);
            pwm.setPWM(Servo_4, 0, Servo4_MAX);
            // Add your code here for Gripper 2
            break;
        case 3:
            pwm.setPWM(Servo_5, 0, Servo5_MAX);
            pwm.setPWM(Servo_6, 0, Servo6_MAX);
            // Add your code here for Gripper 3
            break;
        case 4:
            pwm.setPWM(Servo_7, 0, Servo7_MAX);
            pwm.setPWM(Servo_8, 0, Servo8_MAX);
            // Add your code here for Gripper 4
            break;
        case 0:
            pwm.setPWM(Servo_1, 0, Servo1_MAX);
            pwm.setPWM(Servo_2, 0, Servo2_MAX);

            pwm.setPWM(Servo_3, 0, Servo3_MAX);
            pwm.setPWM(Servo_4, 0, Servo4_MAX);

            pwm.setPWM(Servo_5, 0, Servo5_MAX);
            pwm.setPWM(Servo_6, 0, Servo6_MAX);

            pwm.setPWM(Servo_7, 0, Servo7_MAX);
            pwm.setPWM(Servo_8, 0, Servo8_MAX);
            // Add your code here for Gripper 4
            break;
        default:

            pwm.setPWM(Servo_1, 0, Servo1_MAX);
            pwm.setPWM(Servo_2, 0, Servo2_MAX);

            pwm.setPWM(Servo_3, 0, Servo3_MAX);
            pwm.setPWM(Servo_4, 0, Servo4_MAX);

            pwm.setPWM(Servo_5, 0, Servo5_MAX);
            pwm.setPWM(Servo_6, 0, Servo6_MAX);

            pwm.setPWM(Servo_7, 0, Servo7_MAX);
            pwm.setPWM(Servo_8, 0, Servo8_MAX);
            break;
        }
    }
};

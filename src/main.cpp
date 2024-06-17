#include <Arduino.h>
#include <config/pin.h>
#include <config/parameter.h>
#include <lib/i2c/scani2c.h>
#include <lib/Servo/gripper.h>
#include <lib/robotFunction/robot_UDarm.h>

/*
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2400    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
*/
//bool control(int UD);

Gripper Gripper_ = Gripper();
ArmRobot Arm_ = ArmRobot();

String inputString = "";     // a String to hold incoming data
bool stringComplete = false; // whether the string is complete

void setup()
{
  I2cinit();
  Serial.begin(115200);

  Gripper_.Init();
  Arm_.Init();
  while(Arm_.control(MotorUP));

  pinMode(solenoid_valve_UD, OUTPUT);
  digitalWrite(solenoid_valve_UD,1);

  inputString.reserve(200);

  delay(500);
  
}

bool StartBlue = false;
bool StartRed = false;

void loop()
{

  digitalWrite(solenoid_valve_UD,digitalRead(Switch_Blue));
  if (!digitalRead(Switch_Blue))
  {
    StartBlue = true;
    
  }
  /*while (StartBlue)
  {
    delay(300);
    while(Arm_.control(MotorDN));
    //while (control(MotorDN))
    //;

    delay(3000);
    Gripper_.Get(1);
    StartBlue = false;

  }*/
  /*
    digitalWrite(solenoid_valve_UD,1);delay(5000);
    Gripper_.Get(0);
    digitalWrite(solenoid_valve_UD,0);delay(5000);

    */
  /*
    Gripper_.Get(1);
    delay(500);
    Gripper_.Push(1);
    delay(500);

    Gripper_.Get(2);
    delay(500);
    Gripper_.Push(2);
    delay(500);

    Gripper_.Get(3);
    delay(500);
    Gripper_.Push(3);
    delay(500);

    Gripper_.Get(4);
    delay(500);
    Gripper_.Push(4);
    delay(500);

    Gripper_.Get(0);
    delay(500);
    Gripper_.Push(0);
    delay(500);
    */
  /*
    if (stringComplete)
    {
      Serial.println(inputString);
      pwm_ = inputString.toInt();

      // clear the string:
      inputString = "";
      stringComplete = false;
    }

    */
  /*
    pwm.setPWM(Servo_1, 0, Servo1_MAX);
    pwm.setPWM(Servo_2, 0, Servo2_MAX);
    pwm.setPWM(Servo_3, 0, Servo3_MAX);
    pwm.setPWM(Servo_4, 0, Servo4_MAX);
    pwm.setPWM(Servo_5, 0, Servo5_MAX);
    pwm.setPWM(Servo_6, 0, Servo6_MAX);
    pwm.setPWM(Servo_7, 0, Servo7_MAX);
    pwm.setPWM(Servo_8, 0, Servo8_MAX);

    delay(1000);


    pwm.setPWM(Servo_1, 0, Servo1_MIN);
    pwm.setPWM(Servo_2, 0, Servo2_MIN);
    pwm.setPWM(Servo_3, 0, Servo3_MIN);
    pwm.setPWM(Servo_4, 0, Servo4_MIN);
    pwm.setPWM(Servo_5, 0, Servo5_MIN);
    pwm.setPWM(Servo_6, 0, Servo6_MIN);
    pwm.setPWM(Servo_7, 0, Servo7_MIN);
    pwm.setPWM(Servo_8, 0, Servo8_MIN);

    delay(1000);
  */
  /*
  int L1 = digitalRead(LimitSwitch_B_Down);
  int L2 = digitalRead(LimitSwitch_B_Up);
  int B1_ = digitalRead(Switch_Blue);
  int B2_ = digitalRead(Switch_Red);
  */

  /*
    Serial.print(L1);
    Serial.print(",");
    Serial.print(L2);
    Serial.print(",");
    Serial.print(B1_);
    Serial.print(",");
    Serial.print(B2_);
    Serial.print("\n");
  */
  // Scani2c();
  /*
   while (control(MotorDN))
     ;
   delay(1000);
   while (control(MotorUP))
     ;
   delay(1000);*/
}

void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read();
    if (inChar == '\n')
    {
      stringComplete = true;
    }
    else
    {
      inputString += inChar;
    }
  }
}


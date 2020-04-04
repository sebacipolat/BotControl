#include "Motor.h"
#include "Robot.h"

//Motor A
#define enableA  14
#define motorA1  12
#define motorA2  13
//Motor B
#define enableB  4
#define motorB1  5
#define motorB2  16
//LEDS
#define ledFront 2
#define ledIndicator 15

Motor motorA(enableA,motorA1,motorA2);
Motor motorB(enableB,motorB1,motorB2);
Robot *robot;

void setup() {
  // put your setup code here, to run once:
  motorA.setLeftMotor(true);
  motorB.setRightMotor(true);
  robot =new Robot(&motorA,&motorB,ledFront,ledIndicator);
}

void loop() {
  robot->turnON();
  robot->enableFrontLed(true);
  robot->enableIndicatorLed(true);
  robot->forward(); 
  delay(1000);
  robot->enableFrontLed(false);
  robot->enableFrontLed(false);
  robot->backward(); 
  delay(1000);

}

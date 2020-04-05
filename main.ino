#include "Motor.h"
#include "Robot.h"
#include "RobotControl.h"

//WIFI
 char* ssid = "Wifi-Casa";
 char* password =  "starbase2040";

//PINES
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
RobotControl *robotControl;

void setup() {
  // put your setup code here, to run once:
  motorA.setLeftMotor(true);
  motorB.setRightMotor(true);
  robot =new Robot(&motorA,&motorB,ledFront,ledIndicator);
  robotControl= new RobotControl(robot);
  robotControl->connectToWifi(ssid,password);
}

void loop() {
  delay(2000);
  robotControl->startHandler();
  //robot->turnON();
  //robot->enableFrontLed(true);
  //robot->enableIndicatorLed(true);
  //robot->forward(); 
  //delay(1000);
  //robot->enableFrontLed(false);
  //robot->enableFrontLed(false);
  //robot->backward(); 
  //delay(1000);

}

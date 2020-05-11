#include "Robot.h"
#include "Motor.h"

#include <Arduino.h>


Robot::Robot(Motor *motorA,Motor *motorB,byte ledFront,byte ledIndicator) {  
  this->motorA = motorA;
  this->motorB = motorB;
  this->ledFront = ledFront;
  this->ledIndicator = ledIndicator;
  init();
}
void Robot::init() {
  pinMode(ledFront, OUTPUT);
  pinMode(ledIndicator, OUTPUT);
}

void Robot::forward() {
  this->motorA->forward();
  this->motorB->forward();
}
void Robot::backward() {
  this->motorA->backward();
  this->motorB->backward();  
}
void Robot::turnLeft(){
  this->motorA->backward();
  this->motorB->forward();    
}
void Robot::turnRigth() {
  this->motorA->forward();
  this->motorB->backward();    
}
void Robot::pause() {
  this->motorA->pause();
  this->motorB->pause();    
}
void Robot::enableIndicatorLed(boolean value){
  if(value)
    digitalWrite(ledIndicator, HIGH);
  else
    digitalWrite(ledIndicator, LOW);
}
void Robot::enableFrontLed(boolean value){
  if(value)
    digitalWrite(ledFront, HIGH);
  else
    digitalWrite(ledFront, LOW);
}
void Robot::turnON(){
  this->motorA->turnON();
  this->motorB->turnON();
}
void Robot::turnOFF(){
  this->motorA->turnOFF();
  this->motorB->turnOFF();
}

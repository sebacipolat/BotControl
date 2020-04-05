#include "Motor.h"

Motor::Motor(byte enablePin,byte motorPin1,byte motorPin2) {
  // Use 'this->' to make the difference between the
  // 'pin' attribute of the class and the 
  // local variable 'pin' created from the parameter.
  this->enablePin = enablePin;
  this->motorPin1 = motorPin1;
  this->motorPin2 = motorPin2;
  init();
}

void Motor::init() {
  pinMode(enablePin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT); 
  analogWrite (enablePin, 1023);

}
byte Motor::getEnabledPin() {
  return this->enablePin;
}
byte Motor::getMotorPin1() {
  return this->motorPin1;
}
byte Motor::getMotorPin2() {
  return this->motorPin2;
}
void Motor::setLeftMotor(boolean value){
  this->isLeftOrientation=value;
}
void Motor::setRightMotor(boolean value){
  this->isRightOrientation=value;
}
boolean Motor::isLeftMotor(){
  return this->isLeftOrientation;
}
boolean Motor::isRightMotor(){
  return this->isRightOrientation;
}
void Motor::forward(){ 
   digitalWrite(this->motorPin1 , LOW);
   digitalWrite(this->motorPin2, HIGH);   
}
void Motor::backward(){
  digitalWrite(this->motorPin1 , HIGH);
  digitalWrite(this->motorPin2, LOW);  
}
void Motor::turnON(){
  digitalWrite(this->enablePin , HIGH);
}
void Motor::turnOFF(){
  digitalWrite(this->enablePin , LOW);
}

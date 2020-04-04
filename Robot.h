#ifndef Robot_h
#define Robot_h
#include "Motor.h"

#include <Arduino.h>


class Robot {
  
  private:
    Motor *motorA;
    Motor *motorB;
    byte ledFront;
    byte ledIndicator;
    
  public:
    Robot(Motor *motorA,Motor *motorB,byte ledFront,byte ledIndicator);
    void init(); 
    void forward();
    void backward();
    void turnLeft();
    void turnRigth();
    void enableIndicatorLed(boolean value);
    void enableFrontLed(boolean value);
    void turnON();
    void turnOFF();
};

#endif

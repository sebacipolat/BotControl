#ifndef Motor_h
#define Motor_h
#include <Arduino.h>

class Motor {
  
  private:
    byte enablePin;
    byte motorPin1;
    byte motorPin2;
    boolean isLeftOrientation=false;
    boolean isRightOrientation=false;
    
  public:
    Motor(byte enablePin,byte motorPin1,byte motorPin2);
    void init(); 
    void setLeftMotor(boolean value);
    void setRightMotor(boolean value);
    boolean isLeftMotor();
    boolean isRightMotor();
    void turnON();
    void turnOFF();
    void forward();
    void backward();
    byte getEnabledPin();
    byte getMotorPin1();
    byte getMotorPin2();
};
#endif

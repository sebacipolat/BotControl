
#ifndef RobotControl_h
#define RobotControl_h
#include <Arduino.h>
#include "Robot.h"
 #include "ESP8266WiFi.h"

class RobotControl {
   private:
    Robot *robot;
    WiFiServer *wifiServer;

  public:
    RobotControl(Robot *robot);
    void init(); 
    void connectToWifi(char* ssid,char* password);    
    void startHandler();   
    void handleResponse();
};
#endif
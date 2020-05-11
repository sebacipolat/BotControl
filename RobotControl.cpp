
#include "Robot.h"
#include "RobotControl.h"
#include "ESP8266WiFi.h"

RobotControl::RobotControl(Robot *robot){
  this->robot = robot;
  init();
}

void RobotControl::init() {
  Serial.begin(115200);
}
void RobotControl::connectToWifi(char* ssid,char* password){
  this->wifiServer=new WiFiServer(80);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
   }
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
  this->wifiServer->begin();
}

void RobotControl::startHandler(){
    char valueFromSocket;
    WiFiClient client = this->wifiServer->available();
    if (client) {    
          Serial.print("Client connected with IP:");
          Serial.println(client.remoteIP());
          //turn on indicator led
          this->robot->enableIndicatorLed(true);
          while (client.connected()){
            while (client.available()>0){
              handleResponse(client.read());                                                                     
            } 
          }
    }
}
void RobotControl::handleResponse(char valueFromSocket){
  /*
   * KEY MAP
   * w forward
   * a left
   * d right
   * s back
   * q turn on led
   * e turn off led
   * z stop
   * x start
   */
    Serial.println("[received]"+valueFromSocket);
   
    switch(valueFromSocket)
    {
        case 'w':
          Serial.println("[Forward]");
          this->robot->forward();
          delay(1000);
          this->robot->pause();
        break;
        case 's': 
          Serial.println("[Backward]");
          this->robot->backward();
          delay(1000);
          this->robot->pause();
        break;
        case 'a':
          Serial.println("[Left]");
          this->robot->turnLeft();
          delay(500);
          this->robot->pause();
        break;
        case 'd': 
          Serial.println("[Right]");
          this->robot->turnRigth();
          delay(500);
          this->robot->pause();
        break;
        case 'q':
         Serial.println("[LED ON]");
         this->robot->enableFrontLed(true);
        break;
        case 'e': 
         Serial.println("[LED OFF]");
         this->robot->enableFrontLed(false);
        break;
        case 'z': 
         Serial.println("[STOP]");
         this->robot->turnOFF();
        break;
        case 'x': 
         Serial.println("[START]");
         this->robot->turnON();
        break;
        default: 
          Serial.println("[Invalid Command]");
        break;
    }
}

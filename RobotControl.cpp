
#include "Robot.h"
#include "RobotControl.h"
#include "ESP8266WiFi.h"

RobotControl::RobotControl(Robot *robot){
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
              valueFromSocket = client.read();      
              if(valueFromSocket=='a'){
                Serial.write("AAA");
              }else if(valueFromSocket=='b'){
               Serial.write("BBB");
              }              
            } 
          delay(10);
        }
    }
}
void RobotControl::handleResponse(){
}

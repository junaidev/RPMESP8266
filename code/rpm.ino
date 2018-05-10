#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "wserv.h"

const char* ssid = "wifiap";
const char* password =  "pass123";

String clientName;
String server_adr="";

wserv *sobj;


void setup() {
  Serial.println("Reseting pins...");
  //reset pins
  pinMode(12,OUTPUT);
  digitalWrite(12,LOW);

  
  delay(1000);
  Serial.begin(115200);
  
  //reset pin
  sobj=new wserv();

   WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  
  Serial.println(WiFi.localIP());
  sobj->startoperation();
  
  Serial.println("HTTP server started");
  
}

void loop() {
  sobj->handlclient();
  delay(2000);
}


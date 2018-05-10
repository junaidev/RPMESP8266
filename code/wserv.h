#ifndef wserv_h
#define wserv_h

#include <stdint.h>
#include <WString.h>
#include <WiFiClient.h> 
#include <WiFiServer.h> 
#include <ESP8266WebServer.h>


class wserv{
public:

wserv(){
server=new ESP8266WebServer(80);
}

ESP8266WebServer *server;
void urlDecode(String &input);
void startoperation();
void handlclient();

};


#endif

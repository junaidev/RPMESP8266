#include "wserv.h"

#define RELAYPIN 13
void wserv::urlDecode(String &input)
{
  input.replace("%20", " ");
  input.replace("+", " ");
  input.replace("%21", "!");
  input.replace("%22", "\"");
  input.replace("%23", "#");
  input.replace("%24", "$");
  input.replace("%25", "%");
  input.replace("%26", "&");
  input.replace("%27", "\'");
  input.replace("%28", "(");
  input.replace("%29", ")");
  input.replace("%30", "*");
  input.replace("%31", "+");
  input.replace("%2C", ",");
  input.replace("%2E", ".");
  input.replace("%2F", "/");
  input.replace("%2C", ",");
  input.replace("%3A", ":");
  input.replace("%3A", ";");
  input.replace("%3C", "<");
  input.replace("%3D", "=");
  input.replace("%3E", ">");
  input.replace("%3F", "?");
  input.replace("%40", "@");
  input.replace("%5B", "[");
  input.replace("%5C", "\\");
  input.replace("%5D", "]");
  input.replace("%5E", "^");
  input.replace("%5F", "-");
  input.replace("%60", "`");

}

void wserv::startoperation(){

  server->on("/motor", [&](){  
  String htmlpage = "<html><!DOCTYPE html><head></head><style>body{color: #E85151;background: white;font-family: 'verdana'}.topf {position: fixed;top: 0;left: 0;z-index: 999;width: 100%;background: #E85151;color: white;}.centered {display: block;position: absolute;top: 10%;left: 35%;width: 550px;}</style><body><div class='topf'><h1>DC Motor RPM Control</h1><br/>junaidev@hotmail.com</div><div style='padding-top:5em;' class='centered'><br/><br/><form method='POST'><table border='0'><tr><td>SPEED:</td><td> <input type='text' name='t1' value='1000'></td></tr><td><input type='submit' text='Save' style='border-style: solid; border-width: 1px; border-color: #FFFFFF; background-color: #FF6666'></td></tr></table></form><br/><br/></div></body></html>";         
  server->send(200, "text/html", htmlpage.c_str());

        String sped=server->arg("t1");
        urlDecode(sped);
        int spd= sped.toInt();
        analogWrite(12,spd);  
        
       });
  
    server->begin();

}

void wserv::handlclient(){
server->handleClient();}




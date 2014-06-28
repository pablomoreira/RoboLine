#include "digitalin.h"
#include <Arduino.h>

Digitalin::Digitalin()
{

}
void Digitalin::setPort(int _port)
{
  Digitalin::port = _port;
  pinMode(_port,INPUT);
  Digitalin::laststate = digitalRead(Digitalin::port);
}
boolean Digitalin::getState()
{
  Digitalin::state = digitalRead(Digitalin::port);
  
  if((millis() - Digitalin::mark) > 120 && Digitalin::laststate != Digitalin::state)
  {
      //Serial.print("digital:");
      //Serial.print(Digitalin::port);
      //Serial.print("=");
      //Serial.println(Digitalin::state);
      Digitalin::laststate = Digitalin::state;
      Digitalin::mark = millis();
      return true;
  }
   return false;
}

void Digitalin::printState()
{
    String s = "digital:";
    s += Digitalin::port;
    s += "=";
    s += Digitalin::state;
    Serial.println(s);
}


#ifndef DIGITALIN_H
#define DIGITALIN_H
     
//#include <WProgram.h> //It is very important to remember this! note that if you are using Arduino 1.0 IDE, change "WProgram.h" to "Arduino.h"
#include <Arduino.h>


class Digitalin
{
    public:
      Digitalin();
      void setPort(int _port);
      void printState();
      boolean getState();
    private:
      byte port;
      boolean state;
      boolean laststate;
      unsigned long mark;
      
};
     
#endif

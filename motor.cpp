#include "motor.h"
#include <Arduino.h>
Motor::Motor()
{
  
}
void Motor::Begin(char PIN,char rotation)
{
  this->_motor.attach(PIN);
  this->_motor.write(90);
  this->Act(1);
  this->_rotation = rotation;
}

void Motor::Vel(int vel)
{   
  if(vel != this->Vel() && this->_act == 1)
  {
      if(this->_rotation == 1)
      {
          this->_motor.write(90 - vel);         
      }
      else
      {
          this->_motor.write(90 + vel);
      }
    
  }
}
int Motor::Vel()
{
  return abs(90 - this->_motor.read());
}

Motor::~Motor()
{}

void Motor::Act(int _bool)
{
 this->_act = _bool;
}

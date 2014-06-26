#include "driver.h"

Driver::Driver()
{
  
}
void Driver::Attach(Motor* d,Motor* i)
{
  this->_d = d;
  this->_i = i;
  _d->Vel(0);
  _i->Vel(0);
}

Driver::~Driver()
{

}

void Driver::Direction(int _direction)
{

  switch(_direction)
  {
    case RIGHT:
      this->_i->Vel(MAX);
      this->_d->Vel(MIN);
      break;
     case LEFT:
      this->_d->Vel(MAX);
      this->_i->Vel(MIN);
      break;
     case FORWARD:
      this->_d->Vel(MAX);
      this->_i->Vel(MAX);
      break;
     case STOP:
      this->_d->Vel(0);
      this->_i->Vel(0);
      break;
    default:
      this->_d->Vel(0);
      this->_i->Vel(0);
  }
}
void Driver::Run()
{
  
}

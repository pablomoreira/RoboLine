#include <Servo.h>
#include "config.h"
#include "motor.h"
#ifndef driver_h
#define driver_h
#define MAX   6
#define MIN -5
enum enumDirection {RIGHT, LEFT,FORWARD,STOP,UNKNOW};


class Driver{
  public:
    Driver();
    void Attach(Motor* d,Motor* i);
    ~Driver();
    
    void Direction(int accion);
    void Run();
   private:
     int _tiempo;
     int _now;
     Motor* _d;
     Motor* _i;
     enumDirection _direction;
     
};
#endif

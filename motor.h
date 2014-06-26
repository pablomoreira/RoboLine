#include <Servo.h>
#ifndef motor_h
#define motor_h


class Motor{
  public:
    Motor();
    void Begin(char PIN,char rotation);
    ~Motor();
    void Vel(int vel);
    int Vel();
    void Act(int _bool);
   private:
    Servo _motor;
    char _rotation;
    int _endSpeed;
    int _act;
    
};
#endif

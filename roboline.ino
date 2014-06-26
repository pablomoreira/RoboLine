#include "config.h"
#include "motor.h"
#include "driver.h"

#include <Servo.h>

Motor mySmD;
Motor mySmI;
Driver mydriver;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  mySmD.Begin(SMotD,1);
  mySmI.Begin(SMotI,0);
  
  mydriver.Attach(&mySmD,&mySmI);
  
  pinMode(LineaD,OUTPUT);
  pinMode(LineaI,OUTPUT);
  pinMode(LedD,OUTPUT);
  pinMode(LedI,OUTPUT);
  pinMode(LED,OUTPUT);
  unsigned long vart = millis();   
  int count = 0,state = LOW;
  
  while(Init(&vart,&count,50,&state));
  
  
  
}

unsigned long pretime = 0,now;
void loop() {
    
    int tmpD,tmpI;
    boolean b0,b1;
    
    b0 = Touch(A0,LineaD,550,&tmpD);
    b1 = Touch(A1,LineaI,620,&tmpI);
    
    if(b0 == true){
       digitalWrite(LedD,HIGH);
       mydriver.Direction(RIGHT);
    }
    else  
        digitalWrite(LedD,LOW);
       
    if(b1 == true){
      digitalWrite(LedI,HIGH);
      mydriver.Direction(LEFT);
    } else  digitalWrite(LedI,LOW);
    
    if(b1 == false  && b0 == false)
    {
         mydriver.Direction(FORWARD);
    } 
    if(b1 == true  && b0 == true)
    {
         mydriver.Direction(STOP);
    }
    
    
    now = millis();
    if(now - pretime > 150){
      pretime = millis();
      
      Serial.print(" D-> ");
      Serial.print(tmpD);
      
      Serial.print(" I-> ");
      Serial.println(tmpI);
    }
    
}

boolean Touch(int An, int Led,int Limit,int* Val)
{
    boolean ret = false;    
    
    digitalWrite(Led,HIGH);
    delay(1);
    *Val = analogRead(An);
    if( *Val < Limit)
    {
          ret = true;
    }
    digitalWrite(Led,LOW);    
    return ret;    
}

boolean Init(unsigned long* t,int* count,int limit,int* state)
{
     boolean ret = true;
     
     if(millis() -*t > 100)
     {
       *t = millis();
       *state= ~(*state);
       digitalWrite(LED,*state);         
       (*count)++;
       if(*count >= limit) ret = false;
       Serial.println(*count);
     }
     
     return ret;
}

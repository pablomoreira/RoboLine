#include "config.h"
#include "motor.h"
#include "driver.h"
#include "digitalin.h"

#include <Servo.h>

Motor mySmD;
Motor mySmI;
Driver mydriver;
Digitalin sw;

int A0Max;
int A1Max;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sw.setPort(SW);
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
  
  while(Init(&vart,&count,10,&state));
  delay(2000);
  A0Max = Calibrar(A0,LineaD) - 200;
  A1Max = Calibrar(A1,LineaI) - 200;
  Serial.print("A0Max-> ");
  Serial.print(A0Max);
  Serial.print(" A1Max-> ");
  Serial.println(A1Max);
  while(Init(&vart,&count,40,&state));
  
}

unsigned long pretime = 0,now;
void loop() {
    
    int tmpD,tmpI;
    boolean b0,b1; 
    
    b0 = Touch(A0,LineaD,A0Max,&tmpD);
    b1 = Touch(A1,LineaI,A1Max,&tmpI);
    
    
    if(b0 == false && b1 == false)
    {
         mydriver.Direction(FORWARD);
         digitalWrite(LedI,LOW);
         digitalWrite(LedD,LOW);  
    }
    else
    {  
        if(b0 == true && b1 == true)
        {
            mydriver.Direction(STOP);
            digitalWrite(LedI,HIGH);
            digitalWrite(LedD,HIGH);
        }
        else
        {
          if(b0 == true)
          {
               mydriver.Direction(RIGHT); 
               digitalWrite(LedD,HIGH);
               digitalWrite(LedI,LOW);
          }
          else
          {
             if(b1 == true)mydriver.Direction(LEFT);
             digitalWrite(LedI,HIGH);
             digitalWrite(LedD,LOW);
          }
        }
       
    }
    
    now = millis();
    if(now - pretime > 250){
      pretime = millis();
      
      Serial.print(" D-> ");
      Serial.print(tmpD);
      Serial.print(" L-> ");
      Serial.print(b0);
      Serial.print(" I-> ");
      Serial.print(tmpI);
      Serial.print(" L-> ");
      Serial.println(b1);
    }
    
    if(sw.getState())
    {
        mydriver.Direction(STOP);
        mydriver.Run(0);
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
     
     if(millis() -*t > 50)
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

int Calibrar(int An, int Led)
{          
    int val;
    digitalWrite(Led,HIGH);
    delay(1);
    val = analogRead(An);
    digitalWrite(Led,LOW);    
    return  val;
     
}

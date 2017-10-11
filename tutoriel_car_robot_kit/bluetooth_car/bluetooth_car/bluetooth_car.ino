#include "move.h"
#include <SoftwareSerial.h>
#include "mario.h"

volatile int state = LOW;
char getstr;
int ABS=150;
int buzzPin=10;
SoftwareSerial mavoieserie(3, 4); // (TX, RX) (pin Rx BT, pin Tx BT)

void setup()
{ 
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  mavoieserie.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(buzzPin,OUTPUT);
  _mStop();
}

void loop()
  { 
  getstr=mavoieserie.read();
  Serial.println(getstr) ;
  if(getstr=='f')
  {
    _mForward();
  }
  else if(getstr=='b')
  {
    _mBack();
    delay(200);
  }
  else if(getstr=='l')
  {
    _mLeft(ABS);
    delay(200);
  }
  else if(getstr=='r')
  {
   _mRight(ABS);
    delay(200);
  }
  else if(getstr=='s')
  {
     _mStop();
     digitalWrite(LED,LOW);     
  }
  else if(getstr=='x')
  {
     sing(1,buzzPin);
     digitalWrite(LED,HIGH);
     delay(200);     
  }
  else if(getstr=='t')
  {
     sing(2,buzzPin);
     digitalWrite(LED,HIGH);
     delay(200);     
  }     
  else if(getstr=='A')
  {
    stateChange(state);
  }
}


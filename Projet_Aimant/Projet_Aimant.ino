// ajouter les fonctions pour la musique de Mario
#include "mario.h"

// définition des broches utilisées 
int magPin = 12; 
int buzzPin = 9 ; 

const int interval = 10000 ; // attendre 10s avant de sonner
long duration;

unsigned long tempPrec = 0;
int etatPorte     = 0; // fermee
int etatPortePrec = 0; // fermee

void setup() 
{ 
  pinMode(buzzPin, OUTPUT) ;
//  digitalWrite(buzzPin, HIGH);
   
  pinMode(magPin, INPUT); 
  Serial.begin(9600); 
}

void loop() {
  unsigned long tempAct = millis();
  etatPorte = digitalRead(magPin);

  if (etatPorte != etatPortePrec){
    tempPrec = tempAct;
    etatPortePrec = etatPorte ;
  }

  if (tempAct - tempPrec > interval){
    if (etatPorte == 1){
      //Serial.print("Porte fermee depuis (s): ");
      //Serial.print((tempAct - tempPrec)/1000.0);       
      //Serial.print("\n");
    }
    if (etatPorte == 0){
      //Serial.print("Porte ouverte depuis (s): ");
      //Serial.print((tempAct - tempPrec)/1000.0);
      //Serial.print("\n");
      //tone(buzzPin, 1000, 1000) ; 
      sing(1, buzzPin) ;
    }
  }
  
}

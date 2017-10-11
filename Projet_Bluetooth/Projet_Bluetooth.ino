#include <SoftwareSerial.h>

SoftwareSerial mavoieserie(11, 10); // (TX, RX) (pin Rx BT, pin Tx BT)
const int ledPin = 8 ;
const int relPin = 9 ;
char etat ;

void setup()
{
    // Ouvre la voie série avec l'ordinateur
    Serial.begin(9600);
    // Ouvre la voie série avec le module BT
    mavoieserie.begin(9600);
    pinMode(ledPin, OUTPUT) ;
    pinMode(relPin, OUTPUT) ;
    
    digitalWrite(ledPin, LOW) ;
    digitalWrite(relPin, LOW) ;
}
 
void loop() // run over and over
{
  if (mavoieserie.available() > 0) {
    etat = mavoieserie.read() ;
  } 
  else{
    etat = 0 ;
  }
  Serial.println(etat) ;
  
  switch (etat){
    case '1' :
      digitalWrite(ledPin, HIGH);
      break ;
    case 'A' :  
      digitalWrite(ledPin, LOW);
      break ;
    case '2' :  
      digitalWrite(relPin, HIGH) ;
      break ;
    case 'B' :
      digitalWrite(relPin, LOW);  
      break ;      
    default :
      break ;   
  }
}

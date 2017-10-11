#include <Wire.h>
#include "RTClib.h"
 
RTC_DS1307 RTC; //Classe RTC_DS1307
const int ledPin = 8  ;
const int relPin = 9  ;
const int convHM = 60 ; // Convertir Heure - Minute
// Heure initiale
int heureIni  = 19 ;
int minuteIni = 45 ;
int Initi = heureIni * convHM + minuteIni ;

// Heure final
int heureFin  = 23 ;
int minuteFin = 30 ;
int Final = heureFin * convHM + minuteFin ;

 
void setup () {
  Serial.begin(57600); //Démarrage de la communication
  Wire.begin(); //Démarrage de la librairie wire.h
  RTC.begin(); //Démarrage de la librairie RTClib.h
  RTC.adjust(DateTime(__DATE__, __TIME__));
  
  //Si RTC ne fonctionne pas
  if (! RTC.isrunning()) {
    Serial.println("RTC ne fonctionne pas !");
    
    //Met à l'heure à date à laquelle le sketch est compilé
    RTC.adjust(DateTime(__DATE__, __TIME__)); 
    //Cela fonctionne également :
    //RTC.adjust(DateTime("Dec  5 2012","12:00:00")); 
    //RTC.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
    
  pinMode(ledPin, OUTPUT) ;
  pinMode(relPin, OUTPUT) ;
    
  digitalWrite(ledPin, LOW) ;
  digitalWrite(relPin, HIGH) ;
    
}
 
void loop() {
  //Affichage de l'heure
  DateTime now = RTC.now();
  int heures  = now.hour();
  int minutes = now.minute();
  int Maint = heures * convHM + minutes ;
  
  Serial.print(heures);
  Serial.print(" gio ");
  Serial.print(minutes);
  Serial.print(" phut");
  Serial.println();
  Serial.println();
  
  if ( (Maint > Initi) && (Maint < Final)){
    digitalWrite(ledPin, HIGH);
    digitalWrite(relPin, HIGH);
  } else{
    digitalWrite(ledPin, LOW);
    digitalWrite(relPin, LOW);    
  }
   

  delay(10000);

  
}

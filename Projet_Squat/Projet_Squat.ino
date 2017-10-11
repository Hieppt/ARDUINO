#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2) ;
// définition des broches utilisées 
int trigPin = 9 ; 
int echoPin = 8 ;
boolean detecte ; // au debut, l objet n est pas detecte
 
const long seuil = 100    ; // seuil de distance
int distance;
long duration;
int count = 0 ;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Start squating !");
  lcd.setCursor(2, 1);
  lcd.print(count) ;
  lcd.print(" squats");
  pinMode(trigPin , OUTPUT); 
  digitalWrite(trigPin , LOW);
  detecte = false ;
  pinMode(echoPin, INPUT); 
}

void loop() {
  
//======================= CALCUL DE DISTANCE ====================  
// Clears the trigPin
  digitalWrite(trigPin , LOW);
  delayMicroseconds(10);
// Sets the trigPin Pin on HIGH state for 10 micro seconds
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin , LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
// Calculating the distance
  distance= duration*0.034/2;  
//===============================================================

//========================= MAJ DE COUNT ========================
  if ((distance < seuil) && (detecte == false)) { 
    count = count + 1 ;
    detecte = true ;
  }
  else if(distance >= seuil) {
    detecte = false ;
  }
  lcd.setCursor(2, 1);
  lcd.print(count) ;
  lcd.print(" squats");   
  delay(300);  
//===============================================================
  
}

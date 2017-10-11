const int commPin = 3 ;
int valeur = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  valeur = digitalRead(commPin) ; 

  if (valeur == 1){
    digitalWrite(LED_BUILTIN, HIGH) ;
    delay(100) ;
    digitalWrite(LED_BUILTIN, LOW) ;
    delay(100) ; 
  }
  else{
    digitalWrite(LED_BUILTIN, LOW) ;
  }
}

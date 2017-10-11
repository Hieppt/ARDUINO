const int sensorPin = A0;
const float tempPref  = 20.0;
const float maxSensor = 1024.0;
const float maxVoltage= 5.0;
const float offset    = 0.5;
const int convTemp  = 100;

void setup(){
  Serial.begin(9600) ; // ouvrir un port serie
  // boucle sur tous les ports de sortie
  for (int Npin = 2; Npin < 5; Npin++){
    pinMode(Npin,OUTPUT);
    digitalWrite(Npin,LOW);
  }
}

void loop(){
  int sensorVal = analogRead(sensorPin);
  Serial.print("Valeur capteur: ");
  Serial.print(sensorVal);
  
  // convertir la valeur du capteur en tension
  float voltage = (sensorVal/maxSensor) * maxVoltage;
  Serial.print(", Tension: ");
  Serial.print(voltage);  
  
  // convertir la tension en temperature
  float temperature = (voltage - offset) * convTemp;
  Serial.print(", Temperature: ");
  Serial.print(temperature);
  Serial.print(" \n");
 
  // LEDs
  if (temperature >= tempPref+6){
    for (int Npin = 2; Npin < 5; Npin++){
    digitalWrite(Npin,HIGH);
    }
  } 
  else if(temperature < tempPref+6 && temperature >= tempPref+4){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }
  else if(temperature < tempPref+4 && temperature >= tempPref+2){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);  
  }
  delay(1);
}

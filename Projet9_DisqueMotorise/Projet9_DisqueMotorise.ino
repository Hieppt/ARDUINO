const int bouton = 2 ;
const int moteur = 9 ;
int boutonEtat = 0 ;

void setup()
{
  pinMode(bouton,INPUT);
  pinMode(moteur,OUTPUT);  
}

void loop()
{
  boutonEtat = digitalRead(bouton) ;
  if (boutonEtat == HIGH){
    digitalWrite(moteur,HIGH);
  }
  else{
    digitalWrite(moteur,LOW);
  }
  
}


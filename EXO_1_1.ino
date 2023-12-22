# define LED 9 //on défini la variable LED au pin 9

void setup() { //boucle réalisé 1 fois
pinMode(LED,OUTPUT);//initialisation du port 9 comme une sortie
}

void loop() { //boucle répétable
  digitalWrite(LED,HIGH);//mettre la LED à l'état haut
  delay(1500);//attendre 1.5s
  digitalWrite(LED,LOW);//mettre la LED à l'état bas
  delay(1500);//attendre 1.5s

}

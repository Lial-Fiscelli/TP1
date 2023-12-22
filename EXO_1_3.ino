#define LED 9//on défini la variable LED au pin 9
void setup() {//boucle réalisé 1 fois
  pinMode(LED,OUTPUT);//initialisation du port 9 comme une sortie

}

void loop() {//boucle répétable
  analogWrite(LED,64);// mettre la LED à l'état 64/255 soit 25%
  delay(1000);//attendre 1s
  analogWrite(LED,0);// mettre la LED à l'état 0/255 
  delay(1000);//attendre 1s
  analogWrite(LED,192);// mettre la LED à l'état 192/255 soit 75%
  delay(1000);//attendre 1s
  analogWrite(LED,0);// mettre la LED à l'état 0/255 
  delay(1000);//attendre 1s
  analogWrite(LED,255);// mettre la LED à l'état 255/255 soit 100%
  delay(1000);//attendre 1s
  analogWrite(LED,0);// mettre la LED à l'état 0/255 
  delay(1000);//attendre 1s

}
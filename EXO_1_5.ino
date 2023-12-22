#define LED 9//on défini la variable LED au pin 9
int potentio = A0;// variable en entier associée au port analogique 0
int potentio_lu = 0;//variable en entier prend la valeur 0
void setup() {//boucle réalisée 1 fois
  
  pinMode(potentio, INPUT);//initialisation du port A0 comme une entrée
  Serial.begin(9600);//commencer le moniteur
  pinMode(LED,OUTPUT);//initialisation du port 9 comme une sortie
}

void loop() {//boucle répétable
  potentio_lu = analogRead(potentio);// mettre la valeur lue du potentio dans la variable potentio_lu
  potentio_lu = potentio_lu/4 ;//remplacer la valeur potentio_lu par la valeur de potentio_lu divisée par 4 
  Serial.println(potentio_lu);//afficher sur le moniteur la valeur de potentio_lu ,toujours sur la ligne en desous
  delay(50);//attendre 50 ms
  analogWrite(LED,potentio_lu);//mettre la led à l'état de la valeur de potentio_lu
}
int potentio = A0;// variable en entier associer au port analogique 0
int potentio_lu = 0;//variable en entier prend la valeur 0
void setup() {//boucle réalisé 1 fois
  
  pinMode(potentio, INPUT);//initialisation du port A0 comme une entrée
  Serial.begin(9600);//commencer le moniteur

}

void loop() {//boucle répétable
  potentio_lu = analogRead(potentio);// mettre la lecture de potentio dans la variable potentio_lu
  delay(50);//attendre 50ms
  Serial.println(potentio_lu);//afficher sur le moniteur les valeur de potentio_lu ,toujours sur la ligne en desous

}

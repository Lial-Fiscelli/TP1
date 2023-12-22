int r = A2;//variable en entier associée au port analogique 2
int r_lu = 0;//variable en entier associée au port numérique 0
void setup() {//boucle réalisée 1 fois
  
  pinMode(r, INPUT);//initialisation du port A2 comme une entrée
  Serial.begin(9600);//commencer le moniteur

}

void loop() {//boucle répétable
  r_lu = analogRead(r);//mettre la valeur lue de la résistance photovoltaique dans la variable r_lu
  Serial.println(r_lu);//afficher sur le moniteur la valeur de r_lu ,toujours sur la ligne en desous
  delay(50);//attendre 50 ms
  
}
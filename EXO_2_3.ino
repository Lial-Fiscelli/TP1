/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>//importer de la bibliothèque PID_v1.h

#define PIN_INPUT 2//on défini la variable PIN_INPUT au pin 2 (entrée)
#define PIN_OUTPUT 9//on défini la variable PIN_OUTPUT au pin 9 (sortie)
#define PIN_pot 0//on défini la variable PIN_pot au pin 0

int r_lu = 0;//la variable r_lu en entier prend la valeur 0
int pot_value = 0;//la variable pot_value en entier prend la valeur 0

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=0, Ki=10, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);// variable Input prend la valeur analogique de lecture dePIN_INPUT
  pinMode(PIN_pot, INPUT);// on defini PIN_pot comme une entrée
  Serial.begin(9600);//Commence l'affichage de l'ecran en 9600
  //turn the PID on
  myPID.SetMode(AUTOMATIC);//Demarrer la regulation PID
}

void loop()
{
  pot_value = analogRead(PIN_pot);//pot_value prend la valeur analogique de lecture de PIN_pot
  pot_value = pot_value/4;//pot_value est divisée par 4
  Setpoint = pot_value;//Setpoint prend la valeur de pot_value
  Input = analogRead(PIN_INPUT);//Input prend la valeur analogique de lecture de Pin_INPUT
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);//mettre la variable PIN_OUTPUT à l'état de sortie du PID
  Serial.print("valeur d'entrée =");//Affiche valeur d'entrée = sur l'ecran 
  Serial.print(Input);//Affiche la valeur de Input sur l'ecran 
  Serial.print("  ");//Affiche 2 espaces sur l'ecran
  Serial.print("valeur consigne =");//Affiche valeur consigne = sur l'ecran 
  Serial.println(pot_value);//Affiche la valeur de pot_value sur l'ecran 
  delay(500);//attendre 0.5s

}

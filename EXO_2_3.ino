/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>//importer de la bibliothèque PID_v1.h

#define PIN_INPUT 2//on défini la variable PIN_INPUT au pin 2 (entrée)
#define PIN_OUTPUT 9//on défini la variable PIN_OUTPUT au pin 9 (sortie)
#define PIN_pot 0//on défini la variable PIN_pot au pin 0

int r_lu = 0;
int pot_value = 0;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=0, Ki=10, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  pinMode(PIN_pot, INPUT);
  Serial.begin(9600);
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  pot_value = analogRead(PIN_pot);
  pot_value = pot_value/4;
  Setpoint = pot_value;
  Input = analogRead(PIN_INPUT);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);
  Serial.print("valeur d'entrée =");
  Serial.print(Input);
  Serial.print("  ");
  Serial.print("valeur consigne =");
  Serial.println(pot_value);
  delay(500);

}

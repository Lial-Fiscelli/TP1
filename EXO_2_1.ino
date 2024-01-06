#include <PID_v1.h>

/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h> //importer de la bibliothèque PID_v1.h

#define PIN_INPUT 2  //on défini la variable PIN_INPUT au pin 2 (entrée)
#define PIN_OUTPUT 9  //on défini la variable PIN_OUTPUT au pin 9 (sortie)


//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=0, Ki=10, Kd=0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  Setpoint = 50;
  Serial.begin(9600);

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  Input = analogRead(PIN_INPUT);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);
  Serial.println(Input);
}



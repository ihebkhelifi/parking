#include <Arduino.h>
#include "A4988.h"

//Drive setup FULL step
float motorMaxSpeed = 2000.0;
float motorSpeed = 2000.0; //pulse per second
float motorAccel = 1000.0; //87500; //steps/second/second to accelerate
int motorDirPin = 6; //digital pin 6
int motorStepPin = 3; //digital pin 3

A4988 stepper(1, motorStepPin, motorDirPin); 

void setup(){
  
// stepper.setMaxSpeed(motorMaxSpeed);
// stepper.setSpeed(motorSpeed);
// stepper.setAcceleration(motorAccel);
 delay(5000);
}

void loop(){
for ( int sr = 0; sr < 2; sr++){
  delay(100);
  stepper.move(-200);
//  stepper.runToPosition();
  }  
  delay(100);
  stepper.move(-8000);
//  stepper.runToPosition();
  delay(1000);
}

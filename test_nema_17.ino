#include <Arduino.h>
#include "A4988.h"

#define MOTOR_STEPS 80

// All the wires needed for full functionality
#define DIR 32
#define STEP 34 


A4988 stepper(MOTOR_STEPS, DIR, STEP);
 
 
void setup() {
 
  // Sets the two pins as Outputs
    stepper.setRPM(20);
    //stepper.setMicrostep(1);
}
void loop() {
    stepper.move(MOTOR_STEPS);
    
    delay(5000);

}

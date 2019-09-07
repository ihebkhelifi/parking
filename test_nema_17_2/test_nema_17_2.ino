#include <Stepper.h>
const int stepsPerRevolution=200;
Stepper myStepper (stepsPerRevolution, 8,9);

void setup() {

  myStepper.setSpeed(30);

}

void loop() {
  
  myStepper.step(stepsPerRevolution);
  delay(5000);

}

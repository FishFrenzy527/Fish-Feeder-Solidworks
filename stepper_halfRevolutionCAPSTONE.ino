
#include <Stepper.h>
 
// Number of steps per internal motor revolution 
const float STEPS_PER_REV = 32; 
 
//  Amount of Gear Reduction
const float GEAR_RED = 64;
 
// Number of steps per geared output rotation
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
 
// Define Variables
 
// Number of Steps Required
int StepsRequired;
 
// Create Instance of Stepper Class
// The pins used are 8,9,10,11 

const int stepsPerRevolution = 200;

// initialize the stepper library on pins 8 through 11:
Stepper steppermotor(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  steppermotor.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  
  // Rotate CW 1/2 turn slowly
  StepsRequired  =  STEPS_PER_OUT_REV / 2; 
  steppermotor.setSpeed(100);   
  steppermotor.step(StepsRequired);
  delay(2000);
}

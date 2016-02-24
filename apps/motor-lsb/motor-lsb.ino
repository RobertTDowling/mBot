#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"

MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);
MeLSButton button;

const int8_t stop=0;
const int8_t slow=-64;
const int8_t med=-96;

const uint8_t pin = 13;

void setup() {
  pinMode (pin, OUTPUT);
  Serial.begin (115200);
}

void loop() {
  if (button.getStateChanged ()) {
    switch (button.getState())
    {
      case 0:
         MotorL.run(-slow); MotorR.run(slow);  
      	 digitalWrite (pin, 1); button.gotoState (1); break;
      case 1:
         MotorL.run(slow); MotorR.run(slow);  
         button.gotoState (2); break;
      case 2: 
      case 3: 
      default:
         MotorL.run(0); MotorR.run(0);  
	 digitalWrite (pin, 0); button.gotoState (0); break;
    }
  }
  switch (button.getState())
  {
    case 2: digitalWrite (pin, 0); button.gotoState (3); break;
    case 3: digitalWrite (pin, 1); button.gotoState (2); break;
    default: break;
  }
  delay (100);
}


#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"
#include "MeButton.h"

MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);
MeButton button;

void setup()
{
  MotorL.run(-96);
  MotorR.run(64);  
}

void loop()
{
  if (button.isPressed()) {
    MotorL.run(0);
    MotorR.run(0);  
  }    
}

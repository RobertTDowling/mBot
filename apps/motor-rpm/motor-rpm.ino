#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"
#include "MeButton.h"

MeDCMotor MotorL(M1);
MeDCMotor MotorR(M2);
MeButton button;

int l=255, r=0;

#define SENSOR 9

void setup()
{
  pinMode (SENSOR, INPUT);
  Serial.begin (115200);
}

int wait_for=0;
long last_time;
int any = 0;

void loop()
{
  if (button.isPressed()) {
    l = r = 0;
  }
  MotorL.run(l);
  MotorR.run(r);

  // Wait for 0
  // Wait for 1
  // Save time
  // Wait for 0
  // Wait for 1
  // Record time / Save time

  uint8_t sense = digitalRead (SENSOR);
  if (wait_for == 0) {
    if (sense == 0) {
      wait_for = 1;
    }
  } else {
    if (sense == 1) {
      long now = millis ();
      long dtime = now - last_time;
      if (any) {
	Serial.print (" ");
	Serial.print (dtime);
      } else {
        Serial.print (l);
      }
      last_time = now;
      wait_for = 0;
      any++;
      if (any >5) {
        Serial.print ("\n");
        any = 0;
        l = l - 10;
      }
    }
  }
}


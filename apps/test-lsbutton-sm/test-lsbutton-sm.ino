#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"

const uint8_t pin = 13;

MeLSButton button;

void setup() {
  pinMode (pin, OUTPUT);
  Serial.begin (115200);
}

void loop() {
  if (button.getStateChanged ()) {
    switch (button.getState())
    {
      case 0: digitalWrite (pin, 1); button.gotoState (1); break;
      case 1: button.gotoState (2); break;
      case 2: 
      case 3: 
      default: digitalWrite (pin, 0); button.gotoState (0); break;
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


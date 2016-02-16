#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"

const uint8_t pin = 13;

MeButton button;

void setup() {
  button.init ();
  button.nextState (1); // On next press, enter state 1
  pinMode (pin, OUTPUT);
}

void loop() {
  switch (button.getStateChanged ())
  {
    case 0: digitalWrite (pin, 0); button.nextState (1); break;
    case 1: digitalWrite (pin, 1); button.nextState (2); break;
    case 2: button.nextState (0);
    default: break;
  }
  switch (button.getState())
  {
    case 2: digitalWrite (pin, 0); delay (100); button.gotoState (3); break;
    case 3: digitalWrite (pin, 1); delay (100); button.gotoState (2); break;
    default: break;
  }
}


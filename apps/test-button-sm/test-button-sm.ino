#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"

const uint8_t pin = 13;

MeButton button;

void setup() {
  // put your setup code here, to run once:
  button.init ();
  pinMode (pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (button.state) {
    case 0: if (button.isPressed()) {
      button.state=1;
      digitalWrite (pin, 1);
    }
    break;
    case 1: if (!button.isPressed()) {
      button.state=2;
    }
    break;
    case 2: if (button.isPressed()) {
      button.state=3;
      digitalWrite (pin, 0);
    }
    break;
    case 3: if (!button.isPressed()) {
      button.state=0;
    }
    break;
    default:
      button.state = 0;
  }
  delay (20);
}


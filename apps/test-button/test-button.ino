#include <Wire.h>
#include <SoftwareSerial.h>
#include "mCore.h"
#include "MeButton.h"

#define PIN 13 // Blue LED
MeButton button;

void setup()
{
  pinMode (PIN, OUTPUT);
}

void loop()
{
  digitalWrite (PIN, button.isPressed());
  delay(100);
}

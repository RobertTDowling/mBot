#include <Arduino.h>
#include "pins_arduino.h"
#include "MeLSButton.h"

MeLSButton::MeLSButton() : ButtonState (100, 1000)
{
  _pin = A6;
}

MeLSButton::MeLSButton(uint8_t pin) : ButtonState (100, 1000)
{
  _pin = pin;
}

///@brief Read button
///@return 0 for not pressed, 1 for pressed
bool MeLSButton::readButton()
{
  int16_t x =  analogRead (_pin);
  int delta = _lastRead - x;
  _lastRead = x;  
  bool decision =  delta > (_lastRead >> 3);
  Serial.print (x);  Serial.print ("  ");  Serial.print (delta);  Serial.print ("  ");  Serial.println (decision);
  return decision;
}


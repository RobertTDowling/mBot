#include <Arduino.h>
#include "pins_arduino.h"
#include "MeButton.h"

MeButton::MeButton() : ButtonState (20, 200)
{
  _pin = A7;
}

MeButton::MeButton(uint8_t pin) : ButtonState (20, 200)
{
  _pin = pin;
}

///@brief Read button
///@return 0 for not pressed, 1 for pressed
bool MeButton::readButton()
{
  return analogRead (_pin) < 512;
}


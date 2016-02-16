#include <Arduino.h>
#include "pins_arduino.h"
#include "MeButton.h"

MeButton::MeButton()
{
  _pin = A7;
  init ();
}

MeButton::MeButton(uint8_t pin)
{
  _pin = pin;
  init ();
}

///@brief Read button
///@return 0 for not pressed, 1 for pressed
uint8_t MeButton::readButton()
{
   return analogRead (_pin) < 512 ? 1 : 0;
}

bool MeButton::isPressed ()
{
  return readButton();
}

uint8_t MeButton::init ()
{
  state=0;
}


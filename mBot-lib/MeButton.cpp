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

void MeButton::init ()
{
  _state=0;
  _ticker=0;
  _nextState=0;
}

uint8_t MeButton::getState ()
{
  return _state;
}

uint8_t MeButton::getStateChanged ()
{
  if (_ticker) { // button was already pressed
    if (!isPressed()) {
      delay (20);
      _ticker = 0;
    }
  } else { // button was not pressed yet
    if (isPressed()) {
      delay (20);
      _ticker = 1;
      gotoState (_nextState);
      return _nextState;
    }
  }
  return NO_CHANGE;
}

void MeButton::gotoState (uint8_t s)
{
  _state = s;
}

void MeButton::nextState (uint8_t s)
{
  _nextState = s;
}

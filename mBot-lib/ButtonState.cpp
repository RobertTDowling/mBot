#include <Arduino.h>
#include "ButtonState.h"

ButtonState::ButtonState(uint16_t pace, uint16_t deb) : _pace(pace), _debounce(deb)
{
  _userState=0;
  _switchState=0;
  _targetMS = millis ();
}

bool ButtonState::isPressed ()
{
  return readButton();
}

uint8_t ButtonState::getState ()
{
  return _userState;
}

// Update target by inc ms, and handle case where that is already in past
void ButtonState::incrementTarget(long inc)
{
  long ms = millis ();
  while ((_targetMS += inc) <= ms) {
    ;
  }
}

bool ButtonState::getStateChanged ()
{
  // Pace ourselves to run only once every _pace ms
  long ms = millis ();
  if (ms < _targetMS) {
    return false;
  }
  // Ok, it is time for us to run
  incrementTarget (_pace);
  
  if (_switchState) { // button was already pressed
    if (!isPressed()) {
      _switchState = 0;
    }
  } else { // button was not pressed yet
    if (isPressed()) {
      _switchState = 1;
      incrementTarget (_debounce);
      return true;
    }
  }
  return false;
}

void ButtonState::gotoState (uint8_t s)
{
  _userState = s;
}

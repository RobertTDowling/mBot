#include <Arduino.h>
#include "pins_arduino.h"
#include "MeLSButton.h"

MeLSButton::MeLSButton() : ButtonState (100, 1000)
{
  _pin = A6;
  _mean = _var = _lsbState = 0;
}

MeLSButton::MeLSButton(uint8_t pin) : ButtonState (100, 1000)
{
  _pin = pin;
  _mean = _var = _lsbState = 0;
}

#define	ALPHA 1/4
#define NEGLOG2ALPHA 2
#define ONEMINUSALPHA 3
#define TH 100

// From
// http://www-uxsup.csx.cam.ac.uk/~fanf2/hermes/doc/antiforgery/stats.pdf
//
// diff := x - mean
// incr := alpha * diff
// mean := mean + incr
// variance := (1 - alpha) * (variance + diff * incr)

///@brief Read button
///@return 0 for not pressed, 1 for pressed
bool MeLSButton::readButton()
{
  int16_t x =  analogRead (_pin);

  // Exponential Moving Variance
  int16_t diff = x - _mean;
  int16_t incr = diff >> NEGLOG2ALPHA;
  _mean += incr;
  _var = (ONEMINUSALPHA * (_var + (int32_t)diff * incr)) >> NEGLOG2ALPHA;

  bool press = false;
  switch (_lsbState) {
  default:
  case 0: 
    if (_var > TH*TH && x > _mean) {
      _lsbState = 1;
      press = true;
    }
    break;
  case 1:
    if (x > _mean) {
      press = true;
    } else {
      _lsbState = 0;
    }
  }

  Serial.print (x);  Serial.print ("  ");  Serial.println (press);
  return press;
}


#include "Emv.h"

Emv::Emv(int16_t neglog2alpha)
{
  _mean = _var = 0;
  _neglog2alpha = neglog2alpha;
  _oneminusalpha = (1 << neglog2alpha) - 1;
}

//#define	ALPHA 1/4
//#define NEGLOG2ALPHA 2
//#define ONEMINUSALPHA 3

// From
// http://www-uxsup.csx.cam.ac.uk/~fanf2/hermes/doc/antiforgery/stats.pdf
//
// diff := x - mean
// incr := alpha * diff
// mean := mean + incr
// variance := (1 - alpha) * (variance + diff * incr)

int16_t Emv::filter(int16_t x)
{
  // Exponential Moving Variance
  int16_t diff = x - _mean;
  int16_t incr = diff >> _neglog2alpha;
  _mean += incr;
  _var = (_oneminusalpha * (_var + (int32_t)diff * incr)) >> _neglog2alpha;

  return _var;
}

int16_t Emv::var() { return _var; }
int16_t Emv::mean() { return _mean; }

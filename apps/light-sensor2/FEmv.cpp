#include "FEmv.h"

FEmv::FEmv(float alpha)
{
  _alpha = alpha;
  _oneminusalpha = 1-alpha;

  Init ();
}

void FEmv::Init ()
{
  _mean = _var = 0;
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

float FEmv::filter(float x)
{
  // Exponential Moving Variance
  float diff = x - _mean;
  float incr = diff * _alpha;
  _mean += incr;
  _var = _oneminusalpha * (_var + diff * incr);

  return _var;
}

float FEmv::var() { return _var; }
float FEmv::mean() { return _mean; }

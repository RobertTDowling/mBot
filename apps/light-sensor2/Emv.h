#ifndef EMV_H_
#define EMV_H_

#include <stdint.h>

class Emv
{
public:
	Emv(int16_t neglog2alpha);

	int16_t filter(int16_t x);
	int16_t var();
	int16_t mean();
private:
	int32_t _oneminusalpha;
        int32_t _var;
        int16_t _mean;
	int16_t _neglog2alpha;
};
#endif

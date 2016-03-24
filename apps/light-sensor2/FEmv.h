#ifndef FEMV_H_
#define FEMV_H_

#include <stdint.h>

class FEmv
{
public:
	FEmv(float alpha);

	float filter(float x);
	void Init ();
	float var();
	float mean();
private:
	float _oneminusalpha;
        float _var;
        float _mean;
	float _alpha;
};
#endif

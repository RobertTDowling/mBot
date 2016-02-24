#ifndef MELSBUTTON_H_
#define MELSBUTTON_H_

#include <stdint.h>
#include "ButtonState.h"

class MeLSButton : public ButtonState
{
public:
	///@brief ctor
	MeLSButton();
	MeLSButton(uint8_t pin1);

	///@brief Read button
	///@return 0 for not pressed, 1 for pressed
	bool readButton();
private:
        int32_t _var;
        int16_t _mean;
	uint8_t _pin;
	uint8_t _lsbState;
};
#endif

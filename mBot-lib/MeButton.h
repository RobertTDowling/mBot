#ifndef MEBUTTON_H_
#define MEBUTTON_H_

#include <stdint.h>
#include "ButtonState.h"

class MeButton : public ButtonState
{
public:
	///@brief ctor
	MeButton();
	MeButton(uint8_t pin1);

	///@brief Read button
	///@return 0 for not pressed, 1 for pressed
	bool readButton();
private:
	uint8_t _pin;
};
#endif

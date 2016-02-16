#ifndef MEBUTTON_H_
#define MEBUTTON_H_

#include <stdint.h>

class MeButton
{
public:
	///@brief ctor
	MeButton();
	MeButton(uint8_t pin1);

	///@brief Read button
	///@return 0 for not pressed, 1 for pressed
	uint8_t readButton();
	///@brief Test button
	bool isPressed ();

        uint8_t init();
private:
	uint8_t _pin;
public:
        uint8_t state;
};
#endif

#ifndef MEBUTTON_H_
#define MEBUTTON_H_

#include <stdint.h>

#define NO_CHANGE 255

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

        void init();
	uint8_t getState ();
	uint8_t getStateChanged ();
	void nextState (uint8_t s);
	void gotoState (uint8_t s);
private:
	uint8_t _pin;
        uint8_t _state;
	uint8_t _nextState;
        uint8_t _ticker;
};
#endif

#ifndef BUTTONSTATE_H_
#define BUTTONSTATE_H_

#include <stdint.h>

class ButtonState
{
public:
	///@brief ctor
	ButtonState(uint16_t _pace, uint16_t _deb);

	///@brief Read button
	///@return 0 for not pressed, 1 for pressed
	virtual bool readButton() = 0;
	///@brief Test button
	bool isPressed ();

	uint8_t getState ();
	// Return true if button cycled
	bool getStateChanged ();
	void gotoState (uint8_t s);
private:
        void incrementTarget(long inc);
        uint8_t _userState;
        uint8_t _switchState;
        uint16_t _debounce;
        uint16_t _pace;
        long _targetMS;
};
#endif

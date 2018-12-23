#include "StaticColorEffect.h"

#include "FastLED.h"


StaticColorEffect::StaticColorEffect()
{
	this->_isColorFilled = false;
}


StaticColorEffect::~StaticColorEffect()
{
}

void StaticColorEffect::loop()
{
	FastLED.setBrightness(this->_brightness);
	if (!this->_isColorFilled) {
		for (int i = 0; i < this->_numLeds; i++) {
			this->_leds[i] = *this->_color;
		}
	}

	this->_isColorFilled = true;
}
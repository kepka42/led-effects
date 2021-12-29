#include "StaticColorEffect.h"

StaticColorEffect::StaticColorEffect()
{
	this->_isColorFilled = false;
}

void StaticColorEffect::loop()
{
	if (!this->_isColorFilled) {
		FastLED.setBrightness(this->_brightness);
		for (int i = 0; i < this->_numLeds; i++) {
			this->_leds[i] = this->_color;
		}
		this->_isColorFilled = true;
	}
}
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
	FastLED.setBrightness(75);
	if (!this->_isColorFilled) {
		for (int i = 0; i < this->_numLeds; i++) {
			this->_leds[i] = CRGB::White;
		}
	}

	this->_isColorFilled = true;
}
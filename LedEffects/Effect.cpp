#include "Effect.h"
#include "FastLED.h"

Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::init(CRGB *leds, int numLeds)
{
	this->_leds = leds;
	this->_numLeds = numLeds;
}

void Effect::clearLine()
{
	for (int i = 0; i < this->_numLeds; i++) {
		this->_leds[i] = CRGB::Black;
	}
}

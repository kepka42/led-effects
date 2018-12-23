#include "Effect.h"
#include "FastLED.h"

Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::init(CRGB *leds, int numLeds, CRGB *color, int brightness = 50)
{
	this->_leds = leds;
	this->_numLeds = numLeds;
	this->_color = color;
	this->_brightness = brightness;
}

void Effect::clearLine()
{
	for (int i = 0; i < this->_numLeds; i++) {
		this->_leds[i] = CRGB::Black;
	}
}

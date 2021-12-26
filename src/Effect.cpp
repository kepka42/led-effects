#include "Effect.h"
#include "FastLED.h"
#include "Arduino.h"

Effect::Effect()
{
}


Effect::~Effect()
{
}

void Effect::init(CRGB *leds, int numLeds, CRGB *colors, int numColors, int brightness = 50)
{
	this->_leds = leds;
	this->_numLeds = numLeds;
	this->_colors = colors;
	this->_brightness = brightness;
	this->_numColors = numColors;

	this->_color = this->getRandomColor();
}

void Effect::clearLine()
{
	for (int i = 0; i < this->_numLeds; i++) {
		this->_leds[i] = CRGB::Black;
	}
}

CRGB Effect::getRandomColor()
{
	int rand = random(_numColors);
	return this->_colors[rand];
}
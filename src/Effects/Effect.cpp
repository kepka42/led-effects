#include "Effect.h"

Effect::Effect()
{
    this->_delayIsFirstRun = true;
}

Effect::~Effect()
{
}

void Effect::init(CRGB *leds, int numLeds, CRGB *colors, int numColors, int brightness)
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

bool Effect::wait(unsigned long  ms) {
    if (this->_delayIsFirstRun) {
        this->_delayIsFirstRun = false;
        this->_delayFromMs = millis();
        return true;
    }

    if (millis() - this->_delayFromMs >= ms) {
        this->_delayFromMs = millis();
        return true;
    }
    return false;
}

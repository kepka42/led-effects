#include "StarRunEffect.h"

#include "FastLED.h"


StarRunEffect::StarRunEffect()
{
	this->_led = 0;
}


StarRunEffect::~StarRunEffect()
{
}

void StarRunEffect::loop()
{
	FastLED.setBrightness(255);
	this->clearLine();
	if (this->_led >= this->_numLeds) {
		this->_led = 0;
	}

	this->_leds[this->_led] = CRGB::White;
	this->_led++;

	delay(10);
}
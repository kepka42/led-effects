#include "StarRunEffect.h"


StarRunEffect::StarRunEffect()
{
	this->_led = 0;
}


void StarRunEffect::loop()
{
	FastLED.setBrightness(this->_brightness);
	this->clearLine();
	if (this->_led >= this->_numLeds) {
		this->_led = 0;
	}

	this->_leds[this->_led] = this->_color;
	this->_led++;

	delay(30);
}
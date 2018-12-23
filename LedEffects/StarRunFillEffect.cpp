#include "StarRunFillEffect.h"

#include "Arduino.h"
#include "FastLED.h"

StarRunFillEffect::StarRunFillEffect()
{
	this->_led = 0;
}


StarRunFillEffect::~StarRunFillEffect()
{
}

void StarRunFillEffect::loop()
{
	FastLED.setBrightness(75);
	if (this->_led >= this->_numLeds) {
		this->_led = 0;
		this->clearLine();
	}

	this->_leds[this->_led] = CRGB::White;
	this->_led++;

	delay(25);
}
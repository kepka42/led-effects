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
	FastLED.setBrightness(this->_brightness);
	if (this->_led >= this->_numLeds) {
		this->_led = 0;
		this->clearLine();
	}

	this->_leds[this->_led] = *this->_color;
	this->_led++;

	delay(25);
}
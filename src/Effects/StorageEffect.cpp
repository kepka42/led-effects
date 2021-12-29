#include "StorageEffect.h"

StorageEffect::StorageEffect()
{
	this->_numRunningLeds = 30;
	this->_initRunningLeds();
}

void StorageEffect::init(CRGB *leds, int numLeds, CRGB *colors, int numColors, int brightness)
{
	Effect::init(leds, numLeds, colors, numColors, brightness);
	this->_maxLed = numLeds;
}

void StorageEffect::loop()
{
	FastLED.setBrightness(this->_brightness);

	for (int i = this->_numRunningLeds; i > 0; i--) {
		int *currentLed = &this->_runningLeds[i];

		if (*currentLed - 1 >= 0) {
			this->_leds[*currentLed] = this->getRandomColor();
			this->_leds[*currentLed - 1] = CRGB::Black;
		}

		this->_runningLeds[i]++;

		if (this->_maxLed <= *currentLed) {
			this->_maxLed--;
			*currentLed = 0;
		}

		if (this->_maxLed <= 0) {
			this->_maxLed = this->_numLeds;
			this->clearLine();
			delete this->_runningLeds;
			this->_initRunningLeds();
		}

		delay(1);
	}
}

void StorageEffect::_initRunningLeds()
{
	this->_runningLeds = new int[this->_numRunningLeds];

	int pos = 0;
	for (int i = this->_numRunningLeds; i > 0; i--) {
		this->_runningLeds[i] = pos;
		pos -= 10;
	}
}

void StorageEffect::reset() {
    delete this->_runningLeds;
}

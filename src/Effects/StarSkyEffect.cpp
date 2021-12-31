#include "StarSkyEffect.h"

StarSkyEffect::StarSkyEffect(int numStars)
{
	this->_numStars = numStars;
}

void StarSkyEffect::loop()
{
	FastLED.setBrightness(this->_brightness);
	this->clearLine();
	for (int i = 0; i < this->_numStars; i++) {
		int randLed = random(this->_numLeds);
		this->_leds[randLed] = this->getRandomColor();
	}

	delay(300);
}

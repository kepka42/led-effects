#include "StarSkyEffect.h"

StarSkyEffect::StarSkyEffect(int numStars)
{
	this->_numStars = numStars;
}

void StarSkyEffect::loop()
{
    if (!this->wait(1000)) {
        return;
    }

	FastLED.setBrightness(this->_brightness);
	this->clearLine();
	for (int i = 0; i < this->_numStars; i++) {
		int randLed = random(this->_numLeds);
		this->_leds[randLed] = this->getRandomColor();
	}
}

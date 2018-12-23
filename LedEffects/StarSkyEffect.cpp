#include "StarSkyEffect.h"
#include "FastLED.h"
#include "Arduino.h"


StarSkyEffect::StarSkyEffect(int numStars)
{
	this->_numStars = numStars;
}


StarSkyEffect::~StarSkyEffect()
{
}

void StarSkyEffect::loop()
{
	FastLED.setBrightness(255);
	this->clearLine();
	for (int i = 0; i < this->_numStars; i++) {
		int randLed = random(this->_numLeds);
		this->_leds[randLed] = CRGB::White;
	}

	delay(100);
}

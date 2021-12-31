#include "StarRunFillEffect.h"

StarRunFillEffect::StarRunFillEffect()
{
	this->_led = 0;
}


void StarRunFillEffect::loop()
{
    if (this->_isBlinking) {
        if (this->_blinksCount >= MAX_BLINKS_COUNT) {
            this->_isBlinking = !this->_isBlinking;
            this->_blinksCount = 0;
            this->_isBlackLoop = !this->_isBlackLoop;
            return;
        }

        int brightness = (this->_blinksCount % 2) == 0 ? 0 : this->_brightness;
        FastLED.setBrightness(brightness);

        this->_blinksCount++;

        delay(500);
        return;
    }

	FastLED.setBrightness(this->_brightness);
	if (this->_led >= this->_numLeds) {
		this->_led = 0;

        if (this->_isBlackLoop) {
            this->_isBlackLoop = !this->_isBlackLoop;
        } else {
            this->_isBlinking = true;
        }
	}

	this->_leds[this->_led] = this->_isBlackLoop ? CRGB::Black : this->getRandomColor();
	this->_led++;

	delay(100);
}
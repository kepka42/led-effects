#include "SmoothFadeEffect.h"

SmoothFadeEffect::SmoothFadeEffect()
{
	this->_isColorFilled = false;
	this->_currentBrightness = 0;
	this->_isUpBrightness = true;
}


SmoothFadeEffect::~SmoothFadeEffect()
{
}

void SmoothFadeEffect::loop()
{
	FastLED.setBrightness(this->_currentBrightness);
	if (!this->_isColorFilled) {
		for (int i = 0; i < this->_numLeds; i++) {
			this->_leds[i] = this->_color;
		}
		this->_isColorFilled = true;
	}

	if (this->_isUpBrightness) {
		this->_currentBrightness++;
	}
	else {
		this->_currentBrightness--;
	}

	if (this->_currentBrightness >= this->_brightness || this->_currentBrightness <= 0) {
		this->_isUpBrightness = !this->_isUpBrightness;
		this->_isColorFilled = false;
	}

	if (this->_currentBrightness <= 0) {
		this->_color = this->getRandomColor();
	}

	delay(50);
}
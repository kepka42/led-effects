#include "RandomColorSwitchEffect.h"

void RandomColorSwitchEffect::loop() {
    if (!this->wait(5000)) {
        return;
    }

    FastLED.setBrightness(this->_brightness);
    for (int i = 0; i <= this->_numLeds; i++) {
        CRGB color = this->getRandomColor();
        this->_leds[i] = color;
    }
}

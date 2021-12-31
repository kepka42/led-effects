#include "RandomColorSwitchEffect.h"

void RandomColorSwitchEffect::loop() {
    FastLED.setBrightness(this->_brightness);
    for (int i = 0; i <= this->_numLeds; i++) {
        CRGB color = this->getRandomColor();
        this->_leds[i] = color;
    }

    delay(5000);
}
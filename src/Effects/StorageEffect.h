#pragma once

#include "Effect.h"
#include "Arduino.h"
#include "FastLED.h"

class StorageEffect :
	public Effect
{
public:
	StorageEffect();

    void reset() override;
    void loop() override;
	void init(CRGB *leds, int numLeds, CRGB *colors, int numColors, int brightness = 50) override;

private:
	int _maxLed;
	int *_runningLeds;
	int _numRunningLeds;

	void _initRunningLeds();
};


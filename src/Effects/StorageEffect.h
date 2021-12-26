#pragma once

#include "Effect.h"
#include "Arduino.h"
#include "FastLED.h"

class StorageEffect :
	public Effect
{
public:
	StorageEffect();
	~StorageEffect();

	void loop() override;
	void init(CRGB *leds, int numLeds, CRGB *colors, int numColors, int brightness = 50) override;

private:
	int _maxLed;
	int *_runningLeds;
	int _numRunningLeds;
	bool _isBlackLoop;

	void _initRunningLeds();
};


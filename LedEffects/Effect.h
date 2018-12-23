#pragma once
#include "FastLED.h"

class Effect
{
public:
	Effect();
	~Effect();
	virtual void loop() = 0;
	void init(CRGB *leds, int numLeds);
protected:
	CRGB *_leds;
	int _numLeds;

	void clearLine();
};


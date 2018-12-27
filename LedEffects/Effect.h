#pragma once
#include "FastLED.h"

class Effect
{
public:
	Effect();
	~Effect();
	virtual void loop() = 0;
	void init(CRGB *leds, int numLeds, CRGB *colors, int numColors, int brightness = 50);
protected:
	CRGB *_leds;
	CRGB *_colors;
	CRGB _color;

	int _brightness;
	int _numLeds;
	int _numColors;

	void clearLine();
	CRGB getRandomColor();
};


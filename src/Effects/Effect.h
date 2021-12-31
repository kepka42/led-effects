#pragma once

#include "FastLED.h"
#include "Arduino.h"

class Effect
{
public:
	Effect();
    virtual ~Effect();
	virtual void loop() = 0;
	virtual void init(CRGB *leds, int numLeds, CRGB *colors, int numColors, int brightness = 50);
    virtual void reset() {}
protected:
	CRGB *_leds;
	CRGB *_colors;
	CRGB _color;

	int _brightness;
	int _numLeds;
	int _numColors;

	void clearLine();
	CRGB getRandomColor();

    bool wait(unsigned long ms);
private:
    unsigned long _delayFromMs;
    bool _delayIsFirstRun;
};


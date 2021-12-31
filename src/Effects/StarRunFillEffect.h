#pragma once

#include "Effect.h"
#include "Arduino.h"
#include "FastLED.h"

#define MAX_BLINKS_COUNT 6

class StarRunFillEffect :
	public Effect
{
public:
    explicit StarRunFillEffect();

	void loop() override;
private:
	int _led;
	bool _isBlackLoop = false;
    bool _isBlinking = false;
    int _blinksCount = 0;
};


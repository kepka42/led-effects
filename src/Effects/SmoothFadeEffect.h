#pragma once

#include "Effect.h"
#include "Arduino.h"
#include "FastLED.h"

class SmoothFadeEffect :
	public Effect
{
public:
    explicit SmoothFadeEffect();

	void loop() override;
private:
	bool _isColorFilled;
	bool _isUpBrightness;
	int _currentBrightness;
};


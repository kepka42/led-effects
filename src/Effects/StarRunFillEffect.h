#pragma once

#include "Effect.h"
#include "Arduino.h"
#include "FastLED.h"

class StarRunFillEffect :
	public Effect
{
public:
	StarRunFillEffect();
	~StarRunFillEffect();

	void loop() override;
private:
	int _led;
	bool _isBlackLoop = false;
};


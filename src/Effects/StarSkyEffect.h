#pragma once

#include "Effect.h"
#include "FastLED.h"
#include "Arduino.h"

class StarSkyEffect :
	public Effect
{
public:
	explicit StarSkyEffect(int numStars);
	void loop() override;
private:
	int _numStars;
};


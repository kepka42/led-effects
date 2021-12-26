#pragma once

#include "Effect.h"
#include "FastLED.h"
#include "Arduino.h"

class StarSkyEffect :
	public Effect
{
public:
	StarSkyEffect(int numStars);
	~StarSkyEffect();
	void loop() override;
private:
	int _numStars;
};


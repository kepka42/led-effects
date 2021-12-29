#pragma once

#include "Effect.h"
#include "FastLED.h"

class StaticColorEffect :
	public Effect
{
public:
	StaticColorEffect();
	void loop() override;
private:
	bool _isColorFilled;
};


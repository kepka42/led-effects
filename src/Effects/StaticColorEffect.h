#pragma once

#include "Effect.h"
#include "FastLED.h"

class StaticColorEffect :
	public Effect
{
public:
	StaticColorEffect();
	~StaticColorEffect();
	void loop();
private:
	bool _isColorFilled;
};


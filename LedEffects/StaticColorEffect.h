#pragma once
#include "Effect.h"
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


#pragma once
#include "Effect.h"
class StarRunEffect :
	public Effect
{
public:
	StarRunEffect();
	~StarRunEffect();
	void loop();
private:
	int _led;
};


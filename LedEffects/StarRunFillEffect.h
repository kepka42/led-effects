#pragma once
#include "Effect.h"
class StarRunFillEffect :
	public Effect
{
public:
	StarRunFillEffect();
	~StarRunFillEffect();

	void loop();
private:
	int _led;
	bool _isBlackLoop = false;
};


#pragma once
#include "Effect.h"
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


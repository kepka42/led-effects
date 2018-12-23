#pragma once
#include "Effect.h"
class StarSkyEffect :
	public Effect
{
public:
	StarSkyEffect(int numStars);
	~StarSkyEffect();
	virtual void loop() override;
private:
	int _numStars;
};


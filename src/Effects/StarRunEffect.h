#pragma once

#include "Effect.h"
#include "Arduino.h"

class StarRunEffect :
	public Effect
{
public:
	StarRunEffect();
	void loop() override;
private:
	int _led;
};


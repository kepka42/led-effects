#pragma once

#include "Effect.h"
#include "Arduino.h"

class SmoothFadeEffect :
	public Effect
{
public:
	SmoothFadeEffect();
	~SmoothFadeEffect();

	void loop() override;
private:
	bool _isColorFilled;
	bool _isUpBrightness;
	int _currentBrightness;
};


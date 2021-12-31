#ifndef LED_EFFECTS_RANDOMCOLORSWITCHEFFECT_H
#define LED_EFFECTS_RANDOMCOLORSWITCHEFFECT_H

#include "Effect.h"
#include "Arduino.h"
#include "FastLED.h"

class RandomColorSwitchEffect
        : public Effect {
public:
    void loop() override;
};


#endif //LED_EFFECTS_RANDOMCOLORSWITCHEFFECT_H

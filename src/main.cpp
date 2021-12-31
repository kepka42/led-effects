#include "Arduino.h"
#include "FastLED.h"

#include "Effects/Effect.h"
#include "Effects/StarSkyEffect.h"
#include "Effects/StarRunFillEffect.h"
#include "Effects/SmoothFadeEffect.h"
#include "Effects/StorageEffect.h"
#include "Effects/RandomColorSwitchEffect.h"

#define PIN 9
#define NUM_EFFECTS 5
#define NUM_LEDS 100
#define SECONDS_PER_EFFECT 50
#define BRIGHTNESS 200

#define STAR_SKY_NUM_STARS 30
enum EFFECT {
    STAR_SKY,
    STAR_RUN_FILL,
    SMOOTH_FADE,
    RANDOM_COLOR_SWITCH,
    STORAGE
};

CRGB leds[NUM_LEDS];

#define NUM_COLORS 24
CRGB colors[NUM_COLORS] = {
        CRGB::AliceBlue,
        CRGB::Amethyst,
        CRGB::BlanchedAlmond,
        CRGB::BlueViolet,
        CRGB::Chartreuse,
        CRGB::Coral,
        CRGB::CornflowerBlue,
        CRGB::Crimson,
        CRGB::DarkGreen,
        CRGB::DarkOliveGreen,
        CRGB::DarkOrange,
        CRGB::DarkOrchid,
        CRGB::DarkRed,
        CRGB::DarkSeaGreen,
        CRGB::DarkSlateBlue,
        CRGB::DarkViolet,
        CRGB::DeepSkyBlue,
        CRGB::DimGray,
        CRGB::LightSkyBlue,
        CRGB::Lime,
        CRGB::Magenta,
        CRGB::Orange,
        CRGB::PaleGreen,
        CRGB::White
};

byte effects[NUM_EFFECTS] = {
        EFFECT::RANDOM_COLOR_SWITCH,
        EFFECT::STAR_SKY,
        EFFECT::STAR_RUN_FILL,
        EFFECT::SMOOTH_FADE,
        EFFECT::STORAGE,
};
int currentEffectPos;

long startAt; // Time when current effect was started

Effect *currentEffect;

// FUNCTIONS
void clearLine();
void nextEffect();

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(0));

    FastLED.addLeds<NEOPIXEL, PIN>(leds, NUM_LEDS);

    startAt = millis();
    currentEffectPos = 0;
    currentEffect = new RandomColorSwitchEffect();
    currentEffect->init(leds, NUM_LEDS, colors, NUM_COLORS, BRIGHTNESS);
}

void loop() {
    if (millis() - startAt >= SECONDS_PER_EFFECT * (long)1000) {
        nextEffect();
    }

    currentEffect->loop();
    FastLED.show();
}

void nextEffect() {
    if (currentEffectPos >= NUM_EFFECTS - 1) {
        currentEffectPos = 0;
    } else {
        currentEffectPos++;
    }

    currentEffect->reset();
    delete currentEffect;

    switch (effects[currentEffectPos])
    {
        case EFFECT::STAR_SKY:
            currentEffect = new StarSkyEffect(STAR_SKY_NUM_STARS);
            break;
        case EFFECT::STAR_RUN_FILL:
            currentEffect = new StarRunFillEffect();
            break;
        case EFFECT::SMOOTH_FADE:
            currentEffect = new SmoothFadeEffect();
            break;
        case EFFECT::STORAGE:
            currentEffect = new StorageEffect();
            break;
        case EFFECT::RANDOM_COLOR_SWITCH:
            currentEffect = new RandomColorSwitchEffect();
            break;
    }

    currentEffect->init(leds, NUM_LEDS, colors, NUM_COLORS, BRIGHTNESS);
    startAt = millis();
    clearLine();
    FastLED.setBrightness(BRIGHTNESS);
}

void clearLine() {
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
    }
}
#include "Arduino.h"
#include "FastLED.h"

#include "Effects/Effect.h"
#include "Effects/StarSkyEffect.h"
#include "Effects/StarRunFillEffect.h"
#include "Effects/StarRunEffect.h"
#include "Effects/StaticColorEffect.h"
#include "Effects/SmoothFadeEffect.h"
#include "Effects/StorageEffect.h"

#define PIN 9
#define NUM_EFFECTS 6
#define NUM_LEDS 100
#define SECONDS_PER_EFFECT 60
#define BRIGHTNESS 100

#define STAR_SKY_NUM_STARS 3
enum EFFECT {
    STAR_SKY,
    STAR_RUN,
    STAR_RUN_FILL,
    STATIC_COLOR,
    SMOOTH_FADE,
    STORAGE,
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
        EFFECT::STATIC_COLOR,
        EFFECT::STAR_SKY,
        EFFECT::STAR_RUN,
        EFFECT::STAR_RUN_FILL,
        EFFECT::SMOOTH_FADE,
        EFFECT::STORAGE
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
    FastLED.setBrightness(20);

    currentEffectPos = 0;
    startAt = millis();

    currentEffect = new StaticColorEffect();
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
    }
    else {
        currentEffectPos++;
    }

    currentEffect->reset();
    delete currentEffect;

    switch (effects[currentEffectPos])
    {
        case EFFECT::STAR_SKY:
            currentEffect = new StarSkyEffect(STAR_SKY_NUM_STARS);
            break;
        case EFFECT::STAR_RUN:
            currentEffect = new StarRunEffect();
            break;
        case EFFECT::STAR_RUN_FILL:
            currentEffect = new StarRunFillEffect();
            break;
        case EFFECT::STATIC_COLOR:
            currentEffect = new StaticColorEffect();
            break;
        case EFFECT::SMOOTH_FADE:
            currentEffect = new SmoothFadeEffect();
            break;
        case EFFECT::STORAGE:
            currentEffect = new StorageEffect();
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
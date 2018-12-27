#include "FastLED.h"

#include "Effect.h"
#include "StarSkyEffect.h"
#include "StarRunFillEffect.h"
#include "StarRunEffect.h"
#include "StaticColorEffect.h"
#include "SmoothFadeEffect.h"

#define NUM_EFFECTS 5
#define NUM_LEDS 300
#define SECONDS_PER_EFFECT 60
#define BRIGHTNESS 100

#define STAR_SKY_NUM_STARS 3
enum EFFECT {
	STAR_SKY,
	STAR_RUN,
	STAR_RUN_FILL,
	STATIC_COLOR,
	SMOOTH_FADE,
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
	EFFECT::SMOOTH_FADE
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

	FastLED.addLeds<NEOPIXEL, 12>(leds, NUM_LEDS);
	FastLED.setBrightness(20);

	currentEffectPos = 0;
	startAt = millis();

	currentEffect = new StaticColorEffect();
	currentEffect->init(leds, NUM_LEDS, colors, NUM_COLORS, BRIGHTNESS);
}

void loop() {
	Serial.println(millis() - startAt);
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

	delete currentEffect;

	if (effects[currentEffectPos] == EFFECT::STAR_SKY) {
		currentEffect = new StarSkyEffect(STAR_SKY_NUM_STARS);
	}
	else if (effects[currentEffectPos] == EFFECT::STAR_RUN) {
		currentEffect = new StarRunEffect();
	}
	else if (effects[currentEffectPos] == EFFECT::STAR_RUN_FILL) {
		currentEffect = new StarRunFillEffect();
	}
	else if (effects[currentEffectPos] == EFFECT::STATIC_COLOR) {
		currentEffect = new StaticColorEffect();
	}
	else if (effects[currentEffectPos] == EFFECT::SMOOTH_FADE) {
		currentEffect = new SmoothFadeEffect();
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
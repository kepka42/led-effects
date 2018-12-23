#include "FastLED.h"

#include "Effect.h"
#include "StarSkyEffect.h"
#include "StarRunFillEffect.h"
#include "StarRunEffect.h"
#include "StaticColorEffect.h"

#define NUM_EFFECTS 4
#define NUM_LEDS 300
#define SECONDS_PER_EFFECT 60

#define STAR_SKY_NUM_STARS 3
enum EFFECT {
	STAR_SKY = B00001,
	STAR_RUN = B00010,
	STAR_RUN_FILL = B00011,
	STATIC_COLOR = B00100
};

CRGB leds[NUM_LEDS];

byte effects[NUM_EFFECTS] = {
  EFFECT::STAR_SKY,
  EFFECT::STATIC_COLOR,
  EFFECT::STAR_RUN,
  EFFECT::STAR_RUN_FILL,
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
	FastLED.setBrightness(75);

	currentEffectPos = 0;
	startAt = millis();

	currentEffect = new StarSkyEffect(STAR_SKY_NUM_STARS);
	currentEffect->init(leds, NUM_LEDS);
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
	Serial.println("next effect");
	if (currentEffectPos >= NUM_EFFECTS - 1) {
		currentEffectPos = 0;
	}
	else {
		currentEffectPos++;
	}

	Serial.println("start clear effect");
	delete currentEffect;
	Serial.println("clear current effect");
	if (effects[currentEffectPos] == EFFECT::STAR_SKY) {
		currentEffect = new StarSkyEffect(STAR_SKY);
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

	Serial.println("Create new effect");

	currentEffect->init(leds, NUM_LEDS);
	Serial.println("Init effect");
	startAt = millis();
	clearLine();

	Serial.println("Done.");
}

void clearLine() {
	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CRGB::Black;
	}
}
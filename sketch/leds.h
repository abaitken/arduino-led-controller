#ifndef __LEDS_H
#define __LEDS_H

#define FASTLED_INTERNAL
#include "FastLED.h"
#include "colors.h"

#define LED_COUNT      300
#define LED_BRIGHTNESS 25

extern CRGB g_leds[LED_COUNT];
void SetupLEDs();


#endif
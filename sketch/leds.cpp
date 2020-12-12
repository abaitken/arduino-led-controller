#include "leds.h"

#define PIN_LED 4

CRGB g_leds[LED_COUNT];

void SetupLEDs()
{
    FastLED.addLeds<WS2812, PIN_LED, GRB>(g_leds, LED_COUNT);
    FastLED.setBrightness(LED_BRIGHTNESS);

    for (int i = 0; i < LED_COUNT; i++)
        fill_solid(g_leds, LED_COUNT, CRGB::Black);
    g_leds[INDICATOR_LIGHTS] = CRGB::Green;
    FastLED.show();
}
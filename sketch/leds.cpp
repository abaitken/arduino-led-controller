#include "leds.h"

#define PIN_LED 4

CRGB g_leds[LED_COUNT];

void SetupLEDs()
{
    FastLED.addLeds<WS2812, PIN_LED, GRB>(g_leds, LED_COUNT);
    FastLED.setBrightness(LED_BRIGHTNESS);

    for (int i = 0; i < LED_COUNT; i++)
        fill_solid(g_leds, LED_COUNT, CRGB::Red);
    FastLED.show();
    delay(500);
    for (int i = 0; i < LED_COUNT; i++)
        fill_solid(g_leds, LED_COUNT, CRGB::Green);
    FastLED.show();
    delay(500);
    for (int i = 0; i < LED_COUNT; i++)
        fill_solid(g_leds, LED_COUNT, CRGB::Blue);
    FastLED.show();
    delay(500);
    for (int i = 0; i < LED_COUNT; i++)
        fill_solid(g_leds, LED_COUNT, CRGB::White);
    FastLED.show();
    delay(500);
    for (int i = 0; i < LED_COUNT; i++)
        fill_solid(g_leds, LED_COUNT, CRGB::Black);
    FastLED.show();
    delay(500);
}
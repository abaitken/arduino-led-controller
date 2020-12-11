#include "animation_fadeout.h"
#include "leds.h"
#include <math.h>

#define BRIGHTNESS_STEP_ADJUST 1

AnimationFadeOut::AnimationFadeOut(void)
{
}

ANIMATION_STATE AnimationFadeOut::Step(Pattern* pattern)
{
    FastLED.setBrightness(_brightness);
    _brightness -= BRIGHTNESS_STEP_ADJUST;

    if (_brightness > 10)
        return ANIMATION_STATE::IN_PROGRESS;

    for (uint16_t index = 0; index < LED_COUNT; index++)
        g_leds[index] = CRGB::Black;
        
    FastLED.setBrightness(LED_BRIGHTNESS);
    FastLED.show();

    return ANIMATION_STATE::COMPLETE;
}

long AnimationFadeOut::Begin(Pattern* pattern)
{
    _brightness = LED_BRIGHTNESS;

    for (uint16_t index = 0; index < LED_COUNT; index++)
        g_leds[index] = pattern->GetColor(index);
        
    FastLED.show();

    return ceil(LED_BRIGHTNESS / BRIGHTNESS_STEP_ADJUST);
}
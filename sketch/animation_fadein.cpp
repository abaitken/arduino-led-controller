#include "animation_fadein.h"
#include "leds.h"
#include <math.h>

#define BRIGHTNESS_STEP_ADJUST 1

AnimationFadeIn::AnimationFadeIn(void)
{
}

ANIMATION_STATE AnimationFadeIn::Step(Pattern* pattern)
{
    FastLED.setBrightness(_brightness);
    _brightness += BRIGHTNESS_STEP_ADJUST;

    if (_brightness < LED_BRIGHTNESS)
        return ANIMATION_STATE::IN_PROGRESS;

    FastLED.setBrightness(LED_BRIGHTNESS);
    FastLED.show();

    return ANIMATION_STATE::COMPLETE;
}

long AnimationFadeIn::Begin(Pattern* pattern)
{
    _brightness = 0;
    FastLED.setBrightness(_brightness);

    for (uint16_t index = 0; index < LED_COUNT; index++)
        g_leds[index] = pattern->GetColor(index);
        
    FastLED.show();

    return ceil(LED_BRIGHTNESS / BRIGHTNESS_STEP_ADJUST);
}
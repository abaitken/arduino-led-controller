#include "animation_flashing.h"
#include "leds.h"

AnimationFlashing::AnimationFlashing(void)
{
}

ANIMATION_STATE AnimationFlashing::Step(Pattern* pattern)
{

    if (_on)
    {
        FastLED.setBrightness(0);
        _on = false;
    }
    else
    {
        FastLED.setBrightness(LED_BRIGHTNESS);
        _on = true;
        _remainingIterations--;
    }

    FastLED.show();

    if (_remainingIterations > 0)
        return ANIMATION_STATE::IN_PROGRESS;

    FastLED.setBrightness(LED_BRIGHTNESS);
    return ANIMATION_STATE::COMPLETE;
}

long AnimationFlashing::Begin(Pattern* pattern)
{
    _remainingIterations = random(4, 8);

    for (uint16_t index = 0; index < LED_COUNT; index++)
        g_leds[index] = pattern->GetColor(index);
        
    FastLED.show();

    _on = true;
    return _remainingIterations;
}
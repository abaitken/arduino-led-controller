#include "animation_random.h"
#include "leds.h"

AnimationRandomReveal::AnimationRandomReveal(void)
{
}

ANIMATION_STATE AnimationRandomReveal::Step(Pattern *pattern)
{
    int index = random(LED_COUNT);
    g_leds[index] = pattern->GetColor(index);
    FastLED.show();
    _remainingIterations--;
    if (_remainingIterations > 0)
        return ANIMATION_STATE::IN_PROGRESS;

    return ANIMATION_STATE::COMPLETE;
}

long AnimationRandomReveal::Begin(Pattern *pattern)
{
    _remainingIterations = random(200, 400);
    return _remainingIterations;
}
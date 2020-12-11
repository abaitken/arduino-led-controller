#include "animation_fillright.h"
#include "leds.h"

AnimationFillRight::AnimationFillRight(void)
{
}

ANIMATION_STATE AnimationFillRight::Step(Pattern* pattern)
{
    g_leds[_index] = pattern->GetColor(_index);

    FastLED.show();
    _index --;
    
    if (_index > 0)
        return ANIMATION_STATE::IN_PROGRESS;
    return ANIMATION_STATE::COMPLETE;
}

long AnimationFillRight::Begin(Pattern* pattern)
{
    _index = LED_COUNT - 1;
    return LED_COUNT;
}
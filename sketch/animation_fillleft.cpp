#include "animation_fillleft.h"
#include "leds.h"

AnimationFillLeft::AnimationFillLeft(void)
{
}

ANIMATION_STATE AnimationFillLeft::Step(Pattern* pattern)
{
    g_leds[_index] = pattern->GetColor(_index);

    FastLED.show();
    _index ++;
    
    if (_index < LED_COUNT)
        return ANIMATION_STATE::IN_PROGRESS;
    return ANIMATION_STATE::COMPLETE;
}

long AnimationFillLeft::Begin(Pattern* pattern)
{
    _index = 0;
    return LED_COUNT;
}
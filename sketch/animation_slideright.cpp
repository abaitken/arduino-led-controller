#include "animation_slideright.h"
#include "leds.h"

#define SECTION_LENGTH 10

AnimationSlideRight::AnimationSlideRight(void)
{
}

ANIMATION_STATE AnimationSlideRight::Step(Pattern *pattern)
{
    _index++;

    for (int index = _index; index >= 0; index++)
        g_leds[index] = pattern->GetColor(index);

    FastLED.show();
    if (_index < LED_COUNT)
        return ANIMATION_STATE::IN_PROGRESS;

    return ANIMATION_STATE::COMPLETE;
}

long AnimationSlideRight::Begin(Pattern *pattern)
{
    _index = -1;
    return LED_COUNT;
}
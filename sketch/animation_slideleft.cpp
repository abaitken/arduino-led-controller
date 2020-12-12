#include "animation_slideleft.h"
#include "leds.h"

#define SECTION_LENGTH 10

AnimationSlideLeft::AnimationSlideLeft(void)
{
}

ANIMATION_STATE AnimationSlideLeft::Step(Pattern *pattern)
{
    _index--;

    for (int index = _index; index < LED_COUNT; index++)
        g_leds[index] = pattern->GetColor(index);

    FastLED.show();
    if (_index > 0)
        return ANIMATION_STATE::IN_PROGRESS;

    return ANIMATION_STATE::COMPLETE;
}

long AnimationSlideLeft::Begin(Pattern *pattern)
{
    _index = LED_COUNT - 1;
    return LED_COUNT;
}
#include "animation_shiftright.h"
#include "leds.h"

AnimationShiftRight::AnimationShiftRight(void)
{
}

ANIMATION_STATE AnimationShiftRight::Step(Pattern *pattern)
{
    for (int index = 0; index < LED_COUNT; index++)
    {
        int offsetIndex = index + _offset;
        if(offsetIndex >= LED_COUNT)
            offsetIndex = LED_COUNT - offsetIndex;
        g_leds[index] = pattern->GetColor(offsetIndex);
    }

    FastLED.show();
    _offset++;
    if (_offset < LED_COUNT)
        return ANIMATION_STATE::IN_PROGRESS;

    return ANIMATION_STATE::COMPLETE;
}

long AnimationShiftRight::Begin(Pattern *pattern)
{
    _offset = 0;
    return LED_COUNT;
}
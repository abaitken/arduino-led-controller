#include "animation_shiftleft.h"
#include "leds.h"

#define SECTION_LENGTH 10

AnimationShiftLeft::AnimationShiftLeft(void)
{
}

ANIMATION_STATE AnimationShiftLeft::Step(Pattern *pattern)
{

    for (int index = 0; index < LED_COUNT; index++)
    {
        int offsetIndex = index + _offset;
        if(offsetIndex < 0)
            offsetIndex = LED_COUNT + offsetIndex;
        g_leds[index] = pattern->GetColor(offsetIndex);
    }

    FastLED.show();
    _offset--;
    if (_offset >= 0)
        return ANIMATION_STATE::IN_PROGRESS;

    return ANIMATION_STATE::COMPLETE;
}

long AnimationShiftLeft::Begin(Pattern *pattern)
{
    _offset = LED_COUNT;
    return LED_COUNT;
}
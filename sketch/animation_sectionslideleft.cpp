#include "animation_sectionslideleft.h"
#include "leds.h"

#define SECTION_LENGTH 10

AnimationSectionSlideLeft::AnimationSectionSlideLeft(void)
{
}

ANIMATION_STATE AnimationSectionSlideLeft::Step(Pattern *pattern)
{
    _index--;
    g_leds[_index] = pattern->GetColor(_index);

    if (_index + SECTION_LENGTH < LED_COUNT)
        g_leds[_index + SECTION_LENGTH] = CRGB::Black;

    FastLED.show();
    if (_index + SECTION_LENGTH >= 0)
        return ANIMATION_STATE::IN_PROGRESS;

    return ANIMATION_STATE::COMPLETE;
}

long AnimationSectionSlideLeft::Begin(Pattern *pattern)
{
    _index = LED_COUNT;
    return LED_COUNT + SECTION_LENGTH;
}
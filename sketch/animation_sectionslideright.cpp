#include "animation_sectionslideright.h"
#include "leds.h"

#define SECTION_LENGTH 10

AnimationSectionSlideRight::AnimationSectionSlideRight(void)
{
}

ANIMATION_STATE AnimationSectionSlideRight::Step(Pattern *pattern)
{
    _index++;
    g_leds[_index] = pattern->GetColor(_index);

    if (_index - SECTION_LENGTH >= 0)
        g_leds[_index - SECTION_LENGTH] = CRGB::Black;

    FastLED.show();
    if (_index - SECTION_LENGTH < LED_COUNT)
        return ANIMATION_STATE::IN_PROGRESS;

    return ANIMATION_STATE::COMPLETE;
}

long AnimationSectionSlideRight::Begin(Pattern *pattern)
{
    _index = -1;
    return LED_COUNT + SECTION_LENGTH;
}
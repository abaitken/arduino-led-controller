#include "animation_instant.h"
#include "leds.h"

AnimationInstant::AnimationInstant(void)
{
}

ANIMATION_STATE AnimationInstant::Step(Pattern* pattern)
{
    for (uint16_t index = 0; index < LED_COUNT; index++)
        g_leds[index] = pattern->GetColor(index);
        
    FastLED.show();
    return ANIMATION_STATE::COMPLETE;
}

long AnimationInstant::Begin(Pattern* pattern)
{
    return 1;
}
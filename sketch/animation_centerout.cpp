#include "animation_centerout.h"
#include "math.h"
#include "leds.h"

AnimationCenterOut::AnimationCenterOut(void)
{
}

ANIMATION_STATE AnimationCenterOut::Step(Pattern* pattern)
{
    if (_left >= 0)
    {
        g_leds[_left] = pattern->GetColor(_left);
        _left--;
    }
    if (_right < LED_COUNT)
    {
        g_leds[_right] = pattern->GetColor(_right);
        _right++;
    }

    FastLED.show();

    if (_left < 0 && _right >= LED_COUNT)
        return ANIMATION_STATE::COMPLETE;
    return ANIMATION_STATE::IN_PROGRESS;
}

long AnimationCenterOut::Begin(Pattern* pattern)
{
    _left = floor(LED_COUNT / 2);
    _right = ceil(LED_COUNT / 2);
    return LED_COUNT;
}
#include "animation_edgein.h"
#include "leds.h"
#include "math.h"

AnimationEdgeIn::AnimationEdgeIn(void)
{
}

ANIMATION_STATE AnimationEdgeIn::Step(Pattern* pattern)
{    
    if (_left <= _middle)
    {
        g_leds[_left] = pattern->GetColor(_left);
        _left++;
    }
    if (_right >= _middle)
    {
        g_leds[_right] = pattern->GetColor(_right);
        _right--;
    }

    FastLED.show();
    
    if (_left >= _middle && _right <= _middle)
        return ANIMATION_STATE::COMPLETE;
    return ANIMATION_STATE::IN_PROGRESS;
}

long AnimationEdgeIn::Begin(Pattern* pattern)
{
    _middle = floor(LED_COUNT / 2);
    _left = 0;
    _right = LED_COUNT - 1;
    return LED_COUNT;
}
#include "colors.h"
#include "random.h"


CRGB RandomColor()
{
    int value = 255 - random(256);
    if (value < 85)
        return CRGB(255 - value * 3, 0, value * 3);

    if (value < 170)
    {
        value -= 85;
        return CRGB(0, value * 3, 255 - value * 3);
    }

    value -= 170;
    return CRGB(value * 3, 255 - value * 3, 0);
}
#include "pattern_random.h"
#include "color.h"

RandomColorsPattern::RandomColorsPattern(void)
{

}

void RandomColorsPattern::Reset()
{
// TODO : Randomly assign colours here?
}

void RandomColorsPattern::NextState()
{

}

CRGB RandomColorsPattern::GetColor(int index)
{
    return RandomColor();
}
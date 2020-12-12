#ifndef __PATTERN_RANDOM_H
#define __PATTERN_RANDOM_H

#include "pattern.h"

class RandomColorsPattern : public Pattern
{
    public:
        RandomColorsPattern(void);
        virtual void Reset();
        virtual void NextState();
        virtual CRGB GetColor(int index);
};

#endif
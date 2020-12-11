#ifndef __PATTERN_SOLID_H
#define __PATTERN_SOLID_H

#include "pattern.h"

class SolidColorPattern : public Pattern
{
    public:
        SolidColorPattern(void);
        virtual void Reset();
        virtual void NextState();
        virtual CRGB GetColor(int index);

        CRGB Color;
};

#endif
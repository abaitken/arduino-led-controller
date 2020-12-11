#ifndef __PATTERN_H
#define __PATTERN_H

#include "colors.h"

class Pattern
{
    public:
        Pattern(void);
        virtual ~Pattern(void) { }
        virtual void Reset() = 0;
        virtual void NextState() = 0;
        virtual CRGB GetColor(int index) = 0;
};

#endif
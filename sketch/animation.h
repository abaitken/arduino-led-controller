#ifndef __ANIMATION_H
#define __ANIMATION_H

#include "pattern.h"

enum ANIMATION_STATE
{
    IN_PROGRESS = 0,
    COMPLETE = 1
};

class Animation
{
public:
    Animation(void);
    virtual ~Animation(void) {}
    virtual ANIMATION_STATE Step(Pattern *pattern) = 0;

    // Start a new animation. Return the number of steps that will be performed
    virtual long Begin(Pattern *pattern) = 0;
};

#endif
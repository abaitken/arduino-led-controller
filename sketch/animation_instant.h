#ifndef __ANIMATION_INSTANT_H
#define __ANIMATION_INSTANT_H

#include "animation.h"

class AnimationInstant : public Animation
{
public:
    AnimationInstant(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
#ifndef __ANIMATION_SLIDELEFT_H
#define __ANIMATION_SLIDELEFT_H

#include "animation.h"

class AnimationSlideLeft : public Animation
{
private:
    int _index;
public:
    AnimationSlideLeft(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
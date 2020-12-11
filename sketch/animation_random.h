#ifndef __ANIMATION_RANDOM_H
#define __ANIMATION_RANDOM_H

#include "animation.h"

class AnimationRandomReveal : public Animation
{
private:
    int _remainingIterations;
public:
    AnimationRandomReveal(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
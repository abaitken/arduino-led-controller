#ifndef __ANIMATION_FLASHING_H
#define __ANIMATION_FLASHING_H

#include "animation.h"

class AnimationFlashing : public Animation
{
private:
    int _remainingIterations;
    bool _on;

public:
    AnimationFlashing(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
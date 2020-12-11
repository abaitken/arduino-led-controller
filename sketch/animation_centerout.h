#ifndef __ANIMATION_CENTEROUT_H
#define __ANIMATION_CENTEROUT_H

#include "animation.h"

class AnimationCenterOut : public Animation
{
private:
    int _left;
    int _right;

public:
    AnimationCenterOut(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
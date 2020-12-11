#ifndef __ANIMATION_EDGEIN_H
#define __ANIMATION_EDGEIN_H

#include "animation.h"

class AnimationEdgeIn : public Animation
{
private:
    int _middle;
    int _left;
    int _right;

public:
    AnimationEdgeIn(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
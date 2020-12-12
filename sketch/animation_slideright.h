#ifndef __ANIMATION_SLIDERIGHT_H
#define __ANIMATION_SLIDERIGHT_H

#include "animation.h"

class AnimationSlideRight : public Animation
{
private:
    int _index;
public:
    AnimationSlideRight(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
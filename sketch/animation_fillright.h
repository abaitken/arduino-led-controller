#ifndef __ANIMATION_FILLRIGHT_H
#define __ANIMATION_FILLRIGHT_H

#include "animation.h"

class AnimationFillRight : public Animation
{
private:
    int _index;

public:
    AnimationFillRight(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
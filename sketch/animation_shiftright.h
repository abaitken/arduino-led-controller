#ifndef __ANIMATION_SHIFTRIGHT_H
#define __ANIMATION_SHIFTRIGHT_H

#include "animation.h"

class AnimationShiftRight : public Animation
{
private:
    int _offset;
public:
    AnimationShiftRight(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
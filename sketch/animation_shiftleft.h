#ifndef __ANIMATION_SHIFTLEFT_H
#define __ANIMATION_SHIFTLEFT_H

#include "animation.h"

class AnimationShiftLeft : public Animation
{
private:
    int _offset;
public:
    AnimationShiftLeft(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
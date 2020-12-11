#ifndef __ANIMATION_FILLLEFT_H
#define __ANIMATION_FILLLEFT_H

#include "animation.h"

class AnimationFillLeft : public Animation
{
private:
    int _index;

public:
    AnimationFillLeft(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
#ifndef __ANIMATION_CLEARFADEOUT_H
#define __ANIMATION_CLEARFADEOUT_H

#include "animation.h"

class AnimationFadeOut : public Animation
{
private:
    int _brightness;

public:
    AnimationFadeOut(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
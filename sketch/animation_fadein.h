#ifndef __ANIMATION_FADEIN_H
#define __ANIMATION_FADEIN_H

#include "animation.h"

class AnimationFadeIn : public Animation
{
private:
    int _brightness;

public:
    AnimationFadeIn(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
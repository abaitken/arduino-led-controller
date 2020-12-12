#ifndef __ANIMATION_SECTIONSLIDELEFT_H
#define __ANIMATION_SECTIONSLIDELEFT_H

#include "animation.h"

class AnimationSectionSlideLeft : public Animation
{
private:
    int _index;
public:
    AnimationSectionSlideLeft(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
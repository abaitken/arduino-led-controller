#ifndef __ANIMATION_SECTIONSLIDERIGHT_H
#define __ANIMATION_SECTIONSLIDERIGHT_H

#include "animation.h"

class AnimationSectionSlideRight : public Animation
{
private:
    int _index;
public:
    AnimationSectionSlideRight(void);
    virtual ANIMATION_STATE Step(Pattern* pattern);
    virtual long Begin(Pattern* pattern);
};

#endif
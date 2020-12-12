#ifndef __TIMING_CONSTANT_H
#define __TIMING_CONSTANT_H

#include "timing.h"

class TimingConstant : public Timing
{
public:
    TimingConstant(void);
    virtual void Reset(long totalSteps);
    virtual void Delay();
};

#endif
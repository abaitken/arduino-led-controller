#ifndef __TIMING_SLOWDOWN_H
#define __TIMING_SLOWDOWN_H

#include "timing.h"

class TimingSlowDown : public Timing
{
private:
    int _timingChange;
    int _currentDelay;

public:
    TimingSlowDown(void);
    virtual void Reset(long totalSteps);
    virtual void Delay();
};

#endif
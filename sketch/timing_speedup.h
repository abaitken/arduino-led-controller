#ifndef __TIMING_SPEEDUP_H
#define __TIMING_SPEEDUP_H

#include "timing.h"

class TimingSpeedUp : public Timing
{
private:
    int _timingChange;
    int _currentDelay;

public:
    TimingSpeedUp(void);
    virtual void Reset(long totalSteps);
    virtual void Delay();
};

#endif
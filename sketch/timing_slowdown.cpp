#include "timing_slowdown.h"
#include <Arduino.h>
#include <math.h>

#define TIMING_SLOWEST 300
#define TIMING_FASTEST 10

TimingSlowDown::TimingSlowDown(void)
{
}

void TimingSlowDown::Reset(long totalSteps)
{
    _currentDelay = TIMING_FASTEST;
    _timingChange = ceil((TIMING_SLOWEST - TIMING_FASTEST) / totalSteps);
}

void TimingSlowDown::Delay()
{
    delay(_currentDelay);

    if (_currentDelay < TIMING_SLOWEST)
    {
        _currentDelay += _timingChange;
        if (_currentDelay > TIMING_SLOWEST)
            _currentDelay = TIMING_SLOWEST;
    }
}
#include "timing_speedup.h"
#include <Arduino.h>
#include <math.h>

#define TIMING_SLOWEST 300
#define TIMING_FASTEST 10

TimingSpeedUp::TimingSpeedUp(void)
{
}

void TimingSpeedUp::Reset(long totalSteps)
{
    _currentDelay = TIMING_SLOWEST;
    _timingChange = ceil((TIMING_SLOWEST - TIMING_FASTEST) / totalSteps);
}

void TimingSpeedUp::Delay()
{
    delay(_currentDelay);

    if (_currentDelay > TIMING_FASTEST)
    {
        _currentDelay -= _timingChange;
        if (_currentDelay < TIMING_FASTEST)
            _currentDelay = TIMING_FASTEST;
    }
}
#ifndef __TIMING_H
#define __TIMING_H

class Timing
{
    public:
        Timing(void);
        virtual ~Timing(void) { }
        virtual void Reset() = 0;
        virtual void Delay() = 0;
};

#endif
#include "random.h"

void Randomise()
{
    uint32_t seed = 0;
    for (byte i = A0; i < A4; ++i)
    {
        pinMode(i, INPUT);
        seed <<= 6;
        seed += analogRead(i);
    }
    randomSeed(seed);
}

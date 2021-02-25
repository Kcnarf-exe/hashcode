#include "Street.h"

Street::Street(Intersection start, Intersection end)
{
    this->start = start;
    this->end = end;
}

Intersection Street::getStart()
{
    return this->start;
}
Intersection Street::getEnd()
{
    return this->end;
}
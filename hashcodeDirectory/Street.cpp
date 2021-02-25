#include "Street.h"

Street::Street(int start, int end, int id)
{
    this->start = start;
    this->end = end;
    this->id = id;
}

int Street::getStart()
{
    return this->start;
}
int Street::getEnd()
{
    return this->end;
}
int Street::getId()
{
    return this->id;
}
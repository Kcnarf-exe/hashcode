#include "Street.h"

Street::Street(int start, int end, string name)
{
    this->start = start;
    this->end = end;
    this->name = name;
}

int Street::getStart()
{
    return this->start;
}
int Street::getEnd()
{
    return this->end;
}
string Street::getName()
{
    return this->name;
}
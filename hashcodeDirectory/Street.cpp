#include "Street.h"

Street::Street(int start, int end, int id, string name, int L)
{
    this->start = start;
    this->end = end;
    this->id = id;
    this->name = name;
    this->L = L;

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
    string Street::getName()
    {
        return this->name;
    }
    int Street::getL()
    {
        return this->L;
    }
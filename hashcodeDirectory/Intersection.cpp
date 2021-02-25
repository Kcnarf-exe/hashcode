#include "Intersection.h"

Intersection::Intersection(int id)
{
    this->id = id;
}

void Intersection::addInputStreet(int inputStreetId)
{
    this->inputStreetIds.insert(inputStreetId);
}

void Intersection::addOutputStreet(int outputStreetId)
{
    this->outputStreetIds.insert(outputStreetId);
}

void Intersection::changeGreenLightId(int id)
{
    this->currentGreenLightId = id;
}

int Intersection::getGreenLightId()
{
    return this->currentGreenLightId;
}

void Intersection::addGreenLightSchedule(int inputStreetId, int duration)
{
    this->schedule.push_back(make_pair(inputStreetId, duration));
}

vector<pair<int, int>> Intersection::getSchedule()
{
    return schedule;
}

bool Intersection::isOpen()
{
    return this->open;
}

void Intersection::setOpen(bool open)
{
    this->open = open;
}

void Intersection::decrementTimeLight()
{
    if (this->timeLight > 0)
    {
        this->timeLight--;
    }
}
int Intersection::getTimeLight()
{
    return this->timeLight;
}
void Intersection::nextStreet()
{
    if (this->schedule.size() - 1 == this->stepStreet)
    {
        stepStreet = 0;
    }
    else
    {
        stepStreet++;
    }
    this->changeGreenLightId(this->schedule[stepStreet].first);
    this->setTimeLight(this->schedule[stepStreet].second);
}

void Intersection::setTimeLight(int timeLight)
{
    this->timeLight = timeLight;
}

void Intersection::generateSchedule(vector<int> counterStreets, int duration)
{
    vector<pair<int, int>> localSchedule;
    int totalDurationSchedule = 0;
    for (int i = 0; i < counterStreets.size(); ++i)
    {
        if (this->inputStreetIds.find(i) != this->inputStreetIds.end())
        {
            pair<int, int> entrySChedule(i, counterStreets[i]);
            totalDurationSchedule += counterStreets[i];
            localSchedule.push_back(entrySChedule);
        }
    }

    if (totalDurationSchedule > duration)
    { //If there is not enough time to apply the schedule
        for (int i = 0; i < localSchedule.size(); ++i)
        {
            localSchedule[i].second *= (duration / totalDurationSchedule);
        }
    }

    this->schedule = localSchedule;
}
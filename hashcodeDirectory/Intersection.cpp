#include "Intersection.h"

#include<algorithm> // pour la fonction swap
#include <random>

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

void tri_a_bulle(vector<int> t, vector<int> t2)
    
{
    vector<int> t3;
    for (int i = 0; i < t.size(); i++){
        t3.push_back(t[i]);
    }
    int size = t3.size();
	bool en_desordre = true;
	for (int i = 0; i < size && en_desordre; ++i)
	{
		en_desordre = false;
		for (int j = 1; j < size - i; ++j)
			if (t3[j-1] > t[j])
			{
				swap(t3[j], t3[j-1]);
                swap(t2[j], t2[j-1]);
				en_desordre = true;
 			}
	}
}

void Intersection::generateSchedule(vector<int> counterStreets, int duration)
{
    vector<pair<int, int>> localSchedule;
    int totalDurationSchedule = 0;


    for(int counterId = 0; counterId < counterStreets.size(); counterId++){
        if (counterStreets[counterId] == 0){
            continue;
        }
        if( this->inputStreetIds.find(counterId) != this->inputStreetIds.end()){
                pair<int,int> entrySchedule (counterId,(int)(1.5*counterStreets[counterId]));
                totalDurationSchedule += (int)(1.5*counterStreets[counterId]);
                localSchedule.push_back(entrySchedule);
            
        }
    }

    random_shuffle(begin(localSchedule), end(localSchedule));

    if (totalDurationSchedule > duration)
    { //If there is not enough time to apply the schedule
        for (int i = 0; i < localSchedule.size(); ++i)
        {
            localSchedule[i].second *= max(1,(duration / totalDurationSchedule));
        }
    }

    this->schedule = localSchedule;
}
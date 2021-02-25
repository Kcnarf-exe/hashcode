#include "Car.h"

Car::Car(int numberOfStreets, vector<int> listStreets, int minTime)
{
    this->numberOfStreets = numberOfStreets;
    this->listOfStreets = listStreets;
    this->minTime = minTime;
}

int Car::getNumberOfStreets() { return numberOfStreets; }
vector<int> Car::getListOfStreets() { return listOfStreets; }

int Car::getIdStreet() { return idStreetIsIn; }
void Car::setIdStreet(int id) { this->idStreetIsIn = id; }

int Car::getTimeTransition() { return this->timeTransition; }
void Car::setTimeTransition(int time) { this->timeTransition = time; }

void Car::decrementTimeTransition()
{
    if (timeTransition > 0)
    {
        --timeTransition;
    }
}

int Car::getStepStreet()
{
    return this->stepStreet;
}

void Car::incrementStepStreet()
{
    this->stepStreet++;
}

bool Car::isArrived()
{
    return this->arrived;
}

void Car::setArrived(bool arrived)
{
    this->arrived = arrived;
}

int Car::getMinTime()
{
    return this->minTime;
}

#include "Car.h"

Car::Car(int numberOfStreets, vector<int> listStreets, int minTime)
{
    this->numberOfStreets = numberOfStreets;
    this->listOfStreets = listOfStreets;
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

int Car::getMinTime()
{
    return this->minTime;
}

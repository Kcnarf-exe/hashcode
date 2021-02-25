#include "Intersection.h"

Intersection::Intersection(int id, unordered_set<int> inputStreetIds, unordered_set<int> outputStreetIds) {
    this->id = id;
    this->inputStreetIds = inputStreetIds;
    this->outputStreetIds = outputStreetIds;
}

void Intersection::changeGreenLightId(int id){
    this->currentGreenLightId = id;
}

int Intersection::getGreenLightId(){
    return this->currentGreenLightId;
}

void Intersection::addGreenLightSchedule(int inputStreetId, int duration) {
    this->schedule.push_back(make_pair(inputStreetId, duration));
}

vector<pair<int,int>> Intersection::getSchedule() {
    return schedule;
}
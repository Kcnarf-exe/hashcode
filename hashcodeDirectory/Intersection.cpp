#include "Intersection.h"

Intersection::Intersection(unordered_set<int> inputStreetIds, unordered_set<int> outputStreetIds) {
    this->inputStreetIds = inputStreetIds;
    this->outputStreetIds = outputStreetIds;
}

void Intersection::changeGreenLightId(int id){
    this->currentGreenLightId = id;
}

int Intersection::getGreenLightId();
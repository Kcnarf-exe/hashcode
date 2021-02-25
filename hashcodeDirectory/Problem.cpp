#include "Problem.h"

Problem::Problem(string inputFile)
{
    this->inputFile = inputFile;
    this->streetIdCounter = 0;
}

Problem::Problem(string inputFile, string outputFile)
{
    this->inputFile = inputFile;
    this->outputFile = outputFile;
    this->streetIdCounter = 0;
}

void Problem::constructCounterStreet()
{                                                //Count how many cars pass by each street
    vector<int> result(this->streets.size(), 0); //Fill a vect of size streets of zeros
    vector<int> localCarStreetsList;
    for (int i = 0; i < cars.size(); ++i)
    {
        localCarStreetsList = cars[i]->getListOfStreets();
        for (int j = 0; j < localCarStreetsList.size(); ++j)
        {
            ++result[localCarStreetsList[j]]; //Add +1 to the street which the car pass through
        }
    }
    this->counterStreet = result;
};

/**
 * Read the input file and store the content into the attributes of the Problem object
 * 
 * @return true if no error, false otherwise
 */
bool Problem::readInputFile()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Open file
    freopen(this->inputFile.c_str(), "r", stdin);

    cin >> this->D >> this->I >> this->S >> this->V >> this->F;

    Intersection *intersection;
    Street *street;
    string str;

    int counter = this->S;
    int B, E, L;

    while (counter--)
    {
        cin >> B >> E;

        if (this->intersectionsMap.find(B) == this->intersectionsMap.end())
        {
            intersection = new Intersection(B);
            intersectionsMap.insert({B, intersection});
        }

        if (this->intersectionsMap.find(E) == this->intersectionsMap.end())
        {
            intersection = new Intersection(E);
            intersectionsMap.insert({E, intersection});
        }

        cin >> str >> L;

        street = new Street(B, E, streetIdCounter, str, L);
        this->streetsToId[str] = streetIdCounter;
        streetIdCounter++;
        streets.push_back(street);
        //cout << street->getStart() << " " << street->getEnd() << " " << street->getName() << " " << street->getId() << " " << street->getL() << "\n";
    }

    counter = this->V;
    int P, minTime;
    Car *car;
    vector<int> s;

    while (counter--)
    {
        cin >> P;
        minTime = 0;
        s.clear();
        for (int i = 0; i < P; i++)
        {
            cin >> str;
            s.push_back(this->streetsToId[str]);
            minTime += this->streets[this->streetsToId[str]]->getL();
        }
        car = new Car(P, s, minTime);
        cars.push_back(car);
    }

    // Close file and return true if no problem
    // Close file
    return true;
}

/**
 * Solve the problem and store the solution into attributes
 * 
 * @return true if no error, false otherwise
 */
bool Problem::solve()
{

    constructCounterStreet();
    for (int i = 0; i < intersections.size(); ++i)
    {
        intersections[i]->generateSchedule(this->counterStreet, D); //Generate before hand the schedule for each intersection
    }

    /* Set current green light */
    
    for (Intersection* intersection : this->intersections) {
        if (!intersection->getSchedule().empty()) {
            intersection->changeGreenLightId(intersection->getSchedule()[0].first);
            intersection->setTimeLight(intersection->getSchedule()[0].second);
        } else {
            intersection->changeGreenLightId(-1);
            intersection->setTimeLight(0);
        }
    }

    int currentScore = 0;

    int F = 1000;

    int currentStreetId;
    Street* currentStreet;
    int currentIntersectionId;
    Intersection* currentIntersection;

    for (int t = 0; t < this->D; t++) {
        for (Intersection* intersection: this->intersections) {
            intersection->setOpen(true);
            if(intersection->getTimeLight() == 0) {
                intersection->nextStreet();
                continue;
            }
            intersection->decrementTimeLight();
        }
        for (Car* car: this->cars) {
            if (car->isArrived()) {
                continue;
            }
            if (car->getTimeTransition() == 0) {
                //Check if last street
                if (car->getStepStreet() == car->getListOfStreets().size()-1){
                    car->setArrived(true);
                    currentScore += F + (D - t);
                    continue;
                }
                currentStreetId = car->getIdStreet();
                currentStreet = streets[currentStreetId];
                currentIntersectionId = currentStreet->getEnd();
                currentIntersection = intersections[currentIntersectionId];
                if (currentIntersection->getGreenLightId() == currentStreetId && currentIntersection->isOpen()) {
                    currentIntersection->setOpen(false);
                    car->incrementStepStreet();
                    currentStreetId = car->getListOfStreets()[car->getStepStreet()];
                    car->setIdStreet(currentStreetId);
                    car->setTimeTransition(streets[currentStreetId]->getL());
                }
            } else {
                car->decrementTimeTransition();
            }
        }
   
    }
    score = currentScore;
    // Return true if no problem
    return true;
}

/**
 * Write the output file based on info in its attributes
 * 
 * @return true if no problem, false otherwise
 */
bool Problem::writeOutput()
{
    // Check if we have an output file
    if (this->outputFile.empty())
    {
        cout << "Output file not defined" << endl;
        return false;
    }

    // Create and open outputfile
    ofstream output(this->outputFile);

    int A = getNumberOfIntersectionsWithSchedule();
    Intersection *intersection;
    for (int i = 0; i < this->I; i++)
    {
        intersection = intersectionsMap[i];
        if (!intersection->getSchedule().empty())
        {
            output << i << endl;
            output << to_string(intersection->getSchedule().size()) << endl;
            for (pair<int, int> pairValues : intersection->getSchedule())
            {
                cout << streets[pairValues.first]->getName() << " " << pairValues.second << endl;
            }
        }
    }

    // Close outputFile and return true if no problem
    output.close();
    return true;
}

int Problem::getNumberOfIntersectionsWithSchedule()
{
    int sum = 0;
    for (Intersection *intersection : this->intersections)
    {
        if (!intersection->getSchedule().empty())
        {
            sum++;
        }
    }
    return sum;
}

void Problem::freeMem(){
    for(int i=0;i<streets.size();++i){
        delete streets[i];
    }
    for(int i=0;i<cars.size();++i){
        delete cars[i];
    }
    for(int i=0;i<intersections.size();++i){
        delete intersections[i];
    }

}

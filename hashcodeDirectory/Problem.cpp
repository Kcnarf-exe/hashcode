#include "Problem.h"

Problem::Problem(string inputFile)
{
    this->inputFile = inputFile;
}

Problem::Problem(string inputFile, string outputFile)
{
    this->inputFile = inputFile;
    this->outputFile = outputFile;
}

void Problem::constructCounterStreet(){ //Count how many cars pass by each street
    vector<int> result(this->streets.size(),0); //Fill a vect of size streets of zeros
    vector<int> localCarStreetsList;
    for(int i=0;i<cars.size();++i){
        localCarStreetsList = cars[i]->getListOfStreets();
        for(int j=0;j<localCarStreetsList.size();++j){
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

    int counter = this->S;

    while (counter--)
    {
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

    /* do stuff */
    constructCounterStreet();
    for(int i=0; i<intersections.size();++i){
        intersections[i]->generateSchedule(this->counterStreet,D); //Generate before hand the schedule for each intersection
    }

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

    /* do stuff */

    // Close outputFile and return true if no problem
    output.close();
    return true;
}

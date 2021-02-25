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

        if (this->intersectionsMap.find(B) == this->instersectionsMap.end())
        {
            intersection = new Intersection(B);
            intersectionsMap.insert({B, intersection});
        }

        if (this->intersectionsMap.find(E) == this->instersectionsMap.end())
        {
            intersection = new Intersection(E);
            intersectionsMap.insert({E, intersection});
        }

        cin >> str >> L;

        street = new Street(B, E, streetIdCounter, str, L);
        this->streetsToId[street] = streetIdCounter;
        streetIdCounter++;
        streets.push_back(street);
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
            minTime += this->streets[this->streetsToId[str]].getL();
        }
        car = new Car(P, s, minTime);
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

    // Close outputFile and return true if no problem
    output.close();
    return true;
}

int Problem::getNumberOfIntersectionsWithSchedule()
{
    int sum = 0;
    for (Intersection intersection : this->intersections)
    {
        if (intersection->getSchedule())
        {
        }
    }
}

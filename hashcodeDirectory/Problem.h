#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include "Street.h"
#include "Intersection.h"
#include "Car.h"

using namespace std;

class Problem
{
private:
    string inputFile = "";
    string outputFile = "";
    /* attributes for the problem instance (needed to solve the problem) */
    int D;
    int I;
    int S;
    int V;
    int F;
    map<string, int> streetsToId;
    vector<Street *> streets;
    vector<Car *> cars;
    vector<Intersection *> intersections;
    map<int, Intersection *> intersectionsMap;
    int streetIdCounter;

    /* attributes for the solution (needed to write output) */
    int score;
    //For Generating the solution
    vector<int> counterStreet;

public:
    Problem(string inputFile);
    Problem(string inputFile, string outputFile);
    bool readInputFile();
    bool solve();
    bool writeOutput();

    void constructCounterStreet(); //Count how many cars pass by each street

    // For output
    int getNumberOfIntersectionsWithSchedule();

    void freeMem(); //Free memory space

};

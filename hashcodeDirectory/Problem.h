#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <vector>
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
    vector<Street> streets;
    vector<Car> cars;
    vector<Intersection> intersections;
    map<int, Intersection> intersectionsMap;

    map<string, int> streetsToId;

    /* attributes for the solution (needed to write output) */

public:
    Problem(string inputFile);
    Problem(string inputFile, string outputFile);
    bool readInputFile();
    bool solve();
    bool writeOutput();
    int getSteetId(string street);
};
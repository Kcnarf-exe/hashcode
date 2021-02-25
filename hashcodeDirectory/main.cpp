#include "Problem.h"

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    // Arguments management
    cout << "Reading arguments ..." << endl; 
    string inputFile = argv[1];
    string outputFile = argv[2];

    // Create an instance of problem
    cout << "Creating problem instance ..." << endl;
    Problem* problem = new Problem(inputFile, outputFile);

    // Read input
    if (!problem->readInputFile()) {
        cout << "Error while reading the input file" << endl;
        return 1;
    }

    // Solve the problem
    cout << "Solving ..." << endl;
    if (!problem->solve()) {
        cout << "No solution found" << endl;
        return 1;
    }
    cout << "Solution found !" << endl;

    //Write the output
    cout << "Writing output ..." << endl;
    if (!problem->writeOutput()) {
        cout << "Error while writing the output file" << endl;
        return 1;
    }

    problem->freeMem();

    cout << "Done" << endl;
    delete problem;
    return 0;

}
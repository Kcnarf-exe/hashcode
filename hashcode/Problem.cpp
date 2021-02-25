#include "Problem.h"

Problem::Problem(string inputFile, string outputFile) {
    this->inputFile = inputFile;
    this->outputFile = outputFile;
}

/**
 * Read the input file and store the content into the attributes of the Problem object
 * 
 * @return true if no error, false otherwise
 */
bool Problem::readInputFile() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Open file
    freopen(this->inputFile.c_str(), "r", stdin);

    /* do stuff */

    // Close file and return true if no problem
    // Close file
    return true;
}

/**
 * Solve the problem and store the solution into attributes
 * 
 * @return true if no error, false otherwise
 */
bool Problem::solve() {

    /* do stuff */

    // Return true if no problem
}

/**
 * Write the output file based on info in its attributes
 * 
 * @return true if no problem, false otherwise
 */
bool Problem::writeOutput() {
    // Create and open outputfile
    ofstream output(this->outputFile);

    /* do stuff */

    // Close outputFile and return true if no problem
    output.close();
    return true;

}




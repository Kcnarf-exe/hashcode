#include "Score.h"

Score::Score(string inputFile, string outputFile) {
    this->inputFile = inputFile;
    this->outputFile = outputFile;
}

/**
 * Generate the score based on an input and an output file
 * 
 * @return score : if not feasible, return -1
 */ 
int Score::generateScore() {
    /* Get infos from the input file*/
    Problem* problem = new Problem(inputFile);
    if (!problem->readInputFile()) {
        cout << "Error while reading the input file" << endl;
    }
    /* Extract info from the problem instance */

    /* Extract infos from the output file*/
    /* outputInfo = extractInfos(outputfile) */

    /* Check if the output and input are ok (feasible solution) */
    if (!isValid(problem/*,outputInfo*/)){
        return -1;
    }

    int score = 0;
    /* Calculate score based on the problem */



    return score;
}


/**
 * Check if the problem is valid
 * 
 * @return true if ok, false otherwise
 */ 
bool Score::isValid(Problem* inputProblem/*, outputInfo */){
    /* Check a lot of conditions */

    /* ... conditions ...*/

    /* If no error, return true*/

    return true;

}


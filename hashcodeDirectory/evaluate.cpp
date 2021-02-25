#include <iostream>
#include "Score.h"

int main(int argc, char** argv) {
    // Arguments management
    cout << "Reading arguments ..." << endl; 
    string inputFile = argv[1];
    string outputFile = argv[2];

    // Evaluate the score
    cout << "Evaluating the score ..." << endl;
    Score* score = new Score(inputFile, outputFile);
    cout << "Score : " << score->generateScore() << endl;

    return 0;
}
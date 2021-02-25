#include "Problem.h"

using namespace std;

class Score
{
private:
    int score;
    string inputFile;
    string outputFile;
    bool isValid(Problem* inputProblem/*, outputInfo */);
public:
    Score(string inputFile, string outputFile);
    int generateScore();
};
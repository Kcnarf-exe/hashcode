#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Score
{
private:
    int score;
    string inputFile;
    string outputFile;

public:
    Score(string inputFile, string outputFile);
    void generateScore();
    int getScore();
};
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include "Table.h"

using namespace std;

class Score {
    private :
        int score;
        string inputFile;
        string outputFile;
    public :
        Score(string inputFile, string outputFile);
        int generateScore();

}
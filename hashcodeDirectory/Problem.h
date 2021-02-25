#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Problem {
    private :
        string inputFile = "";
        string outputFile = "";
        /* attributes for the problem instance (needed to solve the problem) */

        /* attributes for the solution (needed to write output) */

    public :
        Problem(string inputFile);
        Problem(string inputFile, string outputFile);
        bool readInputFile();
        bool solve();
        bool writeOutput();
};
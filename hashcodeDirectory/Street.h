#include "Problem.h"

using namespace std;

class Street
{
private:
    int start;
    int end;
    string name;

public:
    Street(int start, int end, string name);
    int getStart();
    int getEnd();
    string getName();
};
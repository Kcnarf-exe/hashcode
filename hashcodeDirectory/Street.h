#include "Problem.h"

using namespace std;

class Street
{
private:
    int start;
    int end;
    int id;
    string name;

public:
    Street(int start, int end, int id);
    int getStart();
    int getEnd();
    int getId();
    string getName();
};
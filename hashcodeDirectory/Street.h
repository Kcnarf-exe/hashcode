#include "Problem.h"

using namespace std;

class Street
{
private:
    int start;
    int end;
    int id;

public:
    Street(int start, int end, int id);
    int getStart();
    int getEnd();
    int getId();
};
#include "Problem.h"

using namespace std;

class Street
{
private:
    Intersection start;
    Intersection end;

public:
    Street(Intersection start, Intersection end);
    Intersection getStart();
    Intersection getEnd();
};
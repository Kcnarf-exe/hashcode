using namespace std;

class Street
{
private:
    int start;
    int end;
    int id;
    int L;
    string name;

public:
    Street(int start, int end, int id, int L);
    int getStart();
    int getEnd();
    int getId();
    int getL();
    string getName();
};
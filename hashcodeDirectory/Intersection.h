
#include <vector>
#include <unordered_set>

using namespace std;

class Intersection {
    private :
        int id;
        unordered_set<int> inputStreetIds;
        unordered_set<int> outputStreetIds;
        vector<pair<int,int>> schedule; // (streetId, duration)  : pattern to repeat until the end of the simalution
        int currentGreenLightId;
    public :
        Intersection(int id);
        void addInputStreet(int inputStreetId);
        void addOutputStreet(int outputStreetId);
        void changeGreenLightId(int newGreenLightId);
        int getGreenLightId();
        void addGreenLightSchedule(int incomingStreetId, int duration);        
        vector<pair<int,int>> getSchedule();
};  
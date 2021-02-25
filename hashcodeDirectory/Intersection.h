
#include <vector>

using namespace std;

class Intersection {
    private :
        int id;
        vector<int> inputStreetId;
        vector<int> outputStreetIds;
        vector<pair<int,int>> schedule; // (streetId, duration)  : pattern to repeat until the end of the simalution
        int currentGreenLightId;
    public :
        void changeGreenLightId(int newGreenLightId);
        int getGreenLightId();
        void setGreenLight(int incomingStreetId, int instantT);        
};  
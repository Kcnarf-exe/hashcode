#include <vector>

using namespace std;

class Car {
    private :
        int numberOfStreets;
        vector<int> listOfStreets;
        
    public :
        int getNumberOfStreets();
        vector<int> getListOfStreets();
    
};
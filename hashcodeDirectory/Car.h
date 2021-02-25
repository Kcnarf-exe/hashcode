#include <vector>

using namespace std;

class Car
{
private:
    int numberOfStreets;
    int minTime;
    vector<int> listOfStreets;

    //Variable pour la simu
    int timeTransition; //Si =0 elle est a l intersection a la fin de la rue actuel
    int idStreetIsIn;   //Id of the street where it is now

public:
    Car(int numberOfStreets, vector<int> listStreets, int minTime);
    int getMinTime();
    int getNumberOfStreets();
    vector<int> getListOfStreets();

    int getIdStreet();
    void setIdStreet(int id);

    int getTimeTransition();
    void setTimeTransition(int time);
    void decrementTimeTransition(); //Decrement the timer on the moving car, if <= the it does not move
};
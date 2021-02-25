#include <vector>

using namespace std;

class Car {
    private :
        int numberOfStreets;
<<<<<<< HEAD
        vector<int> listOfStreets; //Contain all id of the street it has to cross
=======
        vector<int> listOfStreets;
>>>>>>> 1dc518c560cddecdb8958e29a2d3ac46868f1b06

        //Variable pour la simu
        int timeTransition; //Si =0 elle est a l intersection a la fin de la rue actuel
        int idStreetIsIn; //Id of the street where it is now

<<<<<<< HEAD
        
=======
>>>>>>> 1dc518c560cddecdb8958e29a2d3ac46868f1b06
    public :
        Car(int numberOfStreets, vector<int> listStreets);
        int getNumberOfStreets();
        vector<int> getListOfStreets();

        int getIdStreet();
        void setIdStreet(int id);

        int getTimeTransition();
        void setTimeTransition(int time);
        void decrementTimeTransition(); //Decrement the timer on the moving car, if <= the it does not move
    
};
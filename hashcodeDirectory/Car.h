#include <vector>

using namespace std;

class Car {
    private :
        int numberOfStreets;
        vector<int> listOfStreets;
<<<<<<< HEAD

        //Variable pour la simu
        int timeTransition; //Si =0 elle est a l intersection a la fin de la rue actuel
        int idStreetIsIn; //Id of the street where it is now

=======
        
>>>>>>> d12d297b07031c86f63e7f5090501997529dc2d9
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
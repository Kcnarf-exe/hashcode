#include <vector>
#include <string>

using namespace std;

class Pizza {
    private:
        int numberOfIngredients;
        vector<int> ingredients;
    public :
        Pizza(int number, vector<int> ingredients);
        int getNumber();
        vector<int> getIngredients();
};
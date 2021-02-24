#include <vector>
#include <string>

using namespace std;

class Pizza {
    private:
        int numberOfIngredients;
        vector<string> ingredients;
    public :
        Pizza(int number, vector<string> ingredients);
        int getNumber();
        vector<string> getIngredients();
}
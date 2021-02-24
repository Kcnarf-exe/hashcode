#include <set>
#include <string>

using namespace std;

class Pizza
{
private:
    int numberOfIngredients;
    set<int> ingredients;

public:
    Pizza(int number, set<int> ingredients);
    int getNumber();
    set<int> getIngredients();
};
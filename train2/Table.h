#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

#include "Pizza.h"

using namespace std;

class Table {
    private:
        string inputFile;
        int M;
        int T2;
        int T3;
        int T4;
        vector<Pizza*> pizzas;
        map<string, int> ingredientsToId;
        int ingredientIdCounter;
    public :
        Table(string inputFile);
        vector<string> split(string str, char delimiter);
        int getIngredientId(string ingredient);

}
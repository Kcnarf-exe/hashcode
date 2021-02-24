#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include <map>

#include "Pizza.h"

using namespace std;

class Table
{
private:
    string inputFile;
    int M;
    int T2;
    int T3;
    int T4;
    vector<Pizza *> pizzas;
    map<string, int> ingredientsToId;
    int ingredientIdCounter;

public:
    Table(string inputFile);
    int getIngredientId(string ingredient);
    int getM();
    int getT2();
    int getT3();
    int getT4();
    map<string, int> getIngredientToIdMap();
    Pizza *getPizza(int id);
    vector<int> greedy(int teamNumber);
    int scorePizza(set<int> ingredients, Pizza* pizza);
    string teamLine( int teamNumber, vector<int> y);
    string teamString(int teamNumber, int x, vector<int> y);
    bool outputFunction(int x2, int x3, int x4, vector<int> y2, vector<int> y3, vector<int> y4);
};

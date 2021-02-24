#include "Score.h"
#include "StringHandler.h"

Score::Score(string inputFile, string outputFile) {
    this->inputFile = inputFile;
    this->outputFile = outputFile;
}

int Score::generateScore() {
    // On créer une instance de problème
    Table table = Table(inputFile);
    int M = table.getM();
    int T2 = table.getT2();
    int T3 = table.getT3();
    int T4 = table.getT4();
    // On check l'output
    ifstream file(outputFile);
    string firstLine;
    getline(file, firstLine);
    int D = stoi(firstLine);
    if (D > M) {
        cout << "More pizzas delivered than available" << endl;
        return -1;
    }

    string line;
    vector<string> info;
    Pizza* pizza;
    int teamNumber;
    int count;
    int countT2;
    int countT3;
    int countT4;

    this->score = 0;

    while (getline(file, line)) {
        info = StringHandler::split(line, ' ');
        teamNumber = stoi(info[0]);
        switch (teamNumber){
            case 2: countT2++; break;
            case 3: countT3++; break;
            case 4: countT4++; break;
        }
        count++;
        info.erase(info.begin());
        set<int> ingredientsIds;
        int pizzaId;
        Pizza* pizza;
        for (string pizzaString : info) {
            pizzaId = stoi(pizzaString);
            pizza = table.getPizza(pizzaId);
            for (int ingredientId: pizza->getIngredients()) {
                ingredientsIds.insert(ingredientId);
            }
        }
        score += pow(ingredientsIds.size(),2);
    }

    if (count != D) {
        cout << "D not equal to the sum of all pizzas" << endl;
        return -1;
    }
    if (countT2 > T2) {
        cout << "Too much pizzas delivered to teams of 2" << endl;
        return -1;
    }
    if (countT3 > T3) {
        cout << "Too much pizzas delivered to teams of 3" << endl;
        return -1;
    }
    if (countT4 > T4) {
        cout << "Too much pizzas delivered to teams of 4" << endl;
        return -1;
    }
    return score;
}


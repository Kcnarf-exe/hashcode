#include "Table.h"

Table::Table(string inputFile) {
    ifstream file(inputFile);
    string firstLine;
    getline(file, firstLine);
    vector<string> infoFirst = split(firstLine, ' ');
    this->M = stoi(infoFirst[0]);
    this->T2 = stoi(infoFirst[1]);
    this->T3 = stoi(infoFirst[2]);
    this->T4 = stoi(infoFirst[3]);
    string line;
    vector<string> info;
    Pizza* pizza;
    int count;
    while (getline(file, line)) {
        info = split(line, ' ');
        count = stoi(info[0]);
        info.erase(info.begin());
        pizza = new Pizza(count, info);
        this->pizzas.push_back(pizza);
    }
    

}

vector<string> Table::split(string str, char delimiter) { 
  vector<string> internal; 
  stringstream ss(str); // Turn the string into a stream. 
  string tok; 
 
  while(getline(ss, tok, delimiter)) { 
    internal.push_back(tok); 
  } 
 
  return internal; 
}

vector<int> Table::greedy(int teamNumber){
  vector<int> solution;
  int scoreIngredients = 0;

  int indexFirstPizza = -1;
  int scorePizza = 0;

  for(int i=0; i<pizzas.size();++i){ //Select the first pizza with the most ingredients in it
    if(pizzas[i]->getNumber()>scorePizza){
      scorePizza = pizzas[i]->getNumber();
      indexFirstPizza = i;
    }
  }

  vector<int> indexList = {indexFirstPizza};
  int scoreTotal = scorePizza;
  vector<int> listIngredients = pizzas[indexFirstPizza]->getIngredients();

  for(int i=1; i<=teamNumber;++i){
    indexList.push_back(0);

    int scoreLocal = 0;
    int scoreSaved = 0;
    int indexSaved = -1;
    for(int i=0; i<pizzas.size();++i){
      scoreLocal = scorePizza(listIngredients,i);
      if(scoreLocal > scoreSaved){ 
        scoreSaved = scoreLocal; 
        indexSaved = i;
      }
    }

    scoreTotal += scoreSaved;
  }

  solution.push_back(scoreTotal);
  for(int i=0;i<indexList.size();++i){
    solution.push_back(indexList[i]);
  }

  return solution;
}

int Table::getIngredientId(string ingredient) {
    bool found = this->ingredientsToId.find(ingredient) == this->ingredientsToId.end();
    if (found){
        return this->ingredientsToId.at(ingredient);
    }
    this->ingredientsToId[ingredient] = ingredientIdCounter;
    ingredientIdCounter++;
    return ingredientIdCounter-1;

}

 int Table::scorePizza(vector<int>listIngredients, int indexPizza){
   

 }
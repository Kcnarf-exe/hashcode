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

  int indexFirstPizza = 0;
  //Pizza* firstPizza = new Pizza(0,NULL);
  int scorePizza = 0;

  for(int i=0; i<pizzas.size();++i){ //Select the first pizza with the most ingredients in it
    if(pizzas[i]->getNumber()>scorePizza){
      indexFirstPizza = i;
    }
  }

  for(int i=1; i<=teamNumber;++i){

  }


  return solution;
}

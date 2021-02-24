#include "Table.h"

Table::Table(string inputFile)
{
  /*ifstream file(inputFile);
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
    }*/

  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen(inputFile.c_str(), "r", stdin);
  cin >> this->M >> this->T2 >> this->T3 >> this->T4;
  Pizza *pizza;
  int counter = this->M;
  int count;
  string str;
  vector<int> vi;
  while (counter--)
  {
    cin >> count;
    vi.clear();
    for (int i = 0; i < count; i++)
    {
      cin >> str;
      vi.push_back(getIngredientId(str));
    }
    pizza = new Pizza(count, vi);
    this->pizzas.push_back(pizza);
  }
}


int Table::getIngredientId(string ingredient)
{
  bool found = this->ingredientsToId.find(ingredient) == this->ingredientsToId.end();
  if (!found)
  {
    return this->ingredientsToId.at(ingredient);
  }
  this->ingredientsToId[ingredient] = ingredientIdCounter;
  ingredientIdCounter++;
  return ingredientIdCounter - 1;
}

int Table::getM()
{
  return this->M;
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
  vector<int> listIngredients = pizzas[indexFirstPizza]->getIngredients(); // MAKE A SET ?

  for(int i=1; i<=teamNumber;++i){
    indexList.push_back(0);

    int scoreLocal = 0;
    int scoreSaved = 0;
    int indexSaved = -1;
    for(int j=0; j<pizzas.size();++j){
      scoreLocal = scorePizza(listIngredients,j);
      if(scoreLocal > scoreSaved){ 
        scoreSaved = scoreLocal; 
        indexSaved = j;
      }
    }
    //Update the ingredients list with the addition of the new pizza

    scoreTotal += scoreSaved;
    indexList[i] = indexSaved;
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


int Table::getT2()
{
  return this->T2;
}

int Table::getT3()
{
  return this->T3;
}

int Table::getT4()
{
  return this->T4;
}

map<string, int> Table::getIngredientToIdMap()
{
  return ingredientsToId;
}

Pizza *Table::getPizza(int id)
{
  return pizzas[id];
}

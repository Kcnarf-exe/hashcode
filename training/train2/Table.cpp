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
  while (counter--)
  {
    cin >> count;
    set<int> vi;
    for (int i = 0; i < count; i++)
    {
      cin >> str;
      vi.insert(getIngredientId(str));
    }
    pizza = new Pizza(count, vi);
    this->pizzas.push_back(pizza);
  }
}


int Table::getIngredientId(string ingredient)
{
  bool found = this->ingredientsToId.find(ingredient) != this->ingredientsToId.end();
  if (found)
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
  int scoreFirstPizza = 0;

  for(int i=0; i<pizzas.size();++i){ //Select the first pizza with the most ingredients in it
    if(pizzas[i]->getNumber()>scoreFirstPizza){
      scoreFirstPizza = pizzas[i]->getNumber();
      indexFirstPizza = i;
    }
  }

  vector<int> indexList = {indexFirstPizza};
  int scoreTotal = scoreFirstPizza;
  set<int> listIngredients = pizzas[indexFirstPizza]->getIngredients();

  for(int i=1; i<teamNumber;++i){
    int scoreLocal = 0;
    int scoreSaved = scorePizza(listIngredients, pizzas[0]);
    int indexSaved = 0;
    for(int j=1; j<pizzas.size();++j){
      scoreLocal = scorePizza(listIngredients, pizzas[j]);
      if(scoreLocal > scoreSaved){ 
        scoreSaved = scoreLocal; 
        indexSaved = j;
      }
    }

    for (int ingredientId: pizzas[indexSaved]->getIngredients()) {
      listIngredients.insert(ingredientId);
    }

    scoreTotal += scoreSaved;
    indexList.push_back(indexSaved);
  }

  solution.push_back(scoreTotal);
  for(int i=0;i<indexList.size();++i){
    solution.push_back(indexList[i]);
  }

  return solution;
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

int Table::scorePizza(set<int> ingredients, Pizza* pizza) {
    set<int> res(ingredients);
    for (int ingredientId: pizza->getIngredients()) {
      res.insert(ingredientId);
    }
    return res.size() - ingredients.size();
}


string Table::teamLine( int teamNumber, vector<int> y){
    string result = to_string(teamNumber);
    for(int i=0; i<y.size();++i){
        result += " "+to_string(y[i]);
    }
    return result;
}

string Table::teamString(int teamNumber, int x, vector<int> y){
    string teamLinePizza = teamLine(teamNumber, y);
    string result = "";
    for(int i=0;i<x;++i){
        result += teamLinePizza +"\n";
    }
    return result;
}


bool Table::outputFunction(int x2, int x3, int x4, vector<int> y2, vector<int> y3, vector<int> y4){
    bool isCorrect = true;
    int numberTeamsDelivered = x2+x3+x4;

    cout <<"Output..." << endl;
    ofstream file("hello.txt");
    file << "hi" << endl;
    file.close();


    ofstream outputFile("outputFile.txt");
    outputFile << to_string(numberTeamsDelivered) + "\n"; //Write the number of teams delivered

    outputFile << teamString(2, x2, y2);
    outputFile << teamString(3, x3, y3);
    outputFile << teamString(4, x4, y4);

    outputFile.close();

    return isCorrect; 
}

void Table::solve(){
  vector<vector<int>> teamSolution;
  for (int i = 2; i <= 4; i++) {
    teamSolution.push_back(greedy(i));
  }
  
  int x2;
  int x3;
  int x4;

  int available = M;

  x4 = min(available/4, T4);
  cout << "x4 "<< x4 << endl;
  available = available-4*x4;

  x3 = min(available/3, T3);
  cout << "x3 "<< x3 << endl;
  available = available - 3*x3;

  x2 = min(available/2, T2);
  cout << "x2 "<< x2 << endl;
  available = available - 2*x2;

  vector<int> y4 = teamSolution[2];
  y4.erase(y4.begin());

  vector<int> y3 = teamSolution[1];
  y3.erase(y3.begin());

  vector<int> y2 = teamSolution[0];
  y2.erase(y2.begin());

  cout << outputFunction(x2,x3,x4,y2,y3,y4) << endl;

}



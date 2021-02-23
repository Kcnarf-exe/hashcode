#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) { 
  vector<string> internal; 
  stringstream ss(str); // Turn the string into a stream. 
  string tok; 
 
  while(getline(ss, tok, delimiter)) { 
    internal.push_back(tok); 
  } 
 
  return internal; 
}

int find_com(vector<string> line_i, vector<string> line_j){
    int res = 0;
    for (int i = 0; i < line_i.size(); i++) {
        for (int j = 0; j < line_j.size(); j++){
            if (line_i[i] == line_j[j]){
                res++;
            }
        }
    }
    return res;
}


int main(int argc, char **argv) {
    ifstream file(argv[1]);
    cout << "File opened" << endl;
    string line;
    getline(file, line);
    vector<string> infoLine = split(line, ' ');
    int M = stoi(infoLine[0]);
    int T2 = stoi(infoLine[1]);
    int T3 = stoi(infoLine[2]);
    int T4 = stoi(infoLine[3]);
    vector<vector<string>> allIngredientsLines;
    vector<int> allNumberOfIngredients;
    vector<string> tempString;
    while (getline(file, line)){
        tempString = split(line, ' ');
        allNumberOfIngredients.push_back(stoi(tempString[0]));
        tempString.erase(tempString.begin());
        allIngredientsLines.push_back(tempString);
    }
    int pizza1 = 0;
    int pizza2 = 0;
    int c1 = allNumberOfIngredients[0];
    int c2 = c1;
    int c_opt = c1;
    int c_pot;
    int c_com;

    for (int i = 0; i < M; i++){
        c1 = allNumberOfIngredients[i];
        for (int j = i; j < M; j++){
            c2 = allNumberOfIngredients[j];
            c_com = find_com(allIngredientsLines[i], allIngredientsLines[j]);
            c_pot = c1+c2-c_com;
            if (c_pot > c_opt){
                pizza1 = i;
                pizza2 = j;
                c_opt = c_pot;
            }
        }
        if (i % 1000 == 0) {
            cout << int(double(i)/M*100) << endl;
        }
    }
    cout << "Best comb : pizza #" << pizza1 << " and pizza #" << pizza2 << endl;
    cout << "#ingredients = " << c_opt << endl; 
    
    return 0;

}
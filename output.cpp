#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

string teamLine( int teamNumber, vector<int> y){
    string result = to_string(teamNumber);
    for(int i=0; i<y.size();++i){
        result += " "+to_string(y[i]);
    }
    return result;
}

string teamString(int teamNumber, int x, vector<int> y){
    string teamLinePizza = teamLine(teamNumber, y);
    string result = "";
    for(int i=0;i<x-1;++i){
        result += teamLinePizza +"\n";
    }
    return result;
}


bool outputFunction(int x2, int x3, int x4, vector<int> y2, vector<int> y3, vector<int> y4){
    bool isCorrect = true;
    int numberPizzaDelivered = x2+x3+x4;
    ofstream outputFile;
    outputFile.open("outputFile.txt");
    outputFile << to_string(numberPizzaDelivered) + "\n"; //Write the number of pizza delivered

    outputFile << teamString(2, x2, y2);
    outputFile << teamString(3, x3, y3);
    outputFile << teamString(4, x4, y4);

    outputFile.close();

    return isCorrect; 
}


int main(){
    int x2 = 2;
    int x3 = 3;
    int x4 = 4;
    vector<int> y2 = {1,2};
    vector<int> y3 = {3,4,5};
    vector<int> y4 = {3,4,5,6};
    if(outputFunction(x2,x3,x4,y2,y3,y4)){cout << "File output written succesfully" << endl; }

 return 0;   
}
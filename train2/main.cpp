#include <bits/stdc++.h>
#include "Score.h"
using namespace std;

int main()
{
    // solution comes here
    ios::sync_with_stdio(0);
    cin.tie(0);
    Table *t = new Table("../data/a_example");
    t->solve();
    Score* score = new Score("../data/a_example", "../data/outputExamples/a_exemple.out");
    cout << score->generateScore() << endl;
}

// g++ -std=c++11 -O2 -Wall main.cpp -o main

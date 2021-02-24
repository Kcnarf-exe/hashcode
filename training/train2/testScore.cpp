#include "Score.h"
int main(int argc, char** argv) {
    Score* score = new Score(argv[1], argv[2]);
    cout << score->generateScore() << endl;
}
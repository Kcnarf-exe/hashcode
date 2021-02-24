#include "Pizza.h"

Pizza::Pizza(int number, vector<string> ingredients) {
    this->numberOfIngredients = number;
    this->ingredients = ingredients;
}

int Pizza::getNumber() {
    return numberOfIngredients;
}

vector<string> Pizza::getIngredients(){
    return ingredients;
}
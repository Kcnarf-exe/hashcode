#include "Pizza.h"

Pizza::Pizza(int number, vector<int> ingredients)
{
    this->numberOfIngredients = number;
    this->ingredients = ingredients;
}

int Pizza::getNumber()
{
    return numberOfIngredients;
}

vector<int> Pizza::getIngredients()
{
    return ingredients;
}
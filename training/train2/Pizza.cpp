#include "Pizza.h"

Pizza::Pizza(int number, set<int> ingredients)
{
    this->numberOfIngredients = number;
    this->ingredients = ingredients;
}

int Pizza::getNumber()
{
    return numberOfIngredients;
}

set<int> Pizza::getIngredients()
{
    return ingredients;
}
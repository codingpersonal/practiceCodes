#pragma once

#include<iostream>
#include<string>
#include "Coffee.h"

using namespace std;

class Factory_Coffee {
public:
	Factory_Coffee();
	Coffee* getCoffeeObject(string coffeeType, string coffeeName, int cupSize);
};
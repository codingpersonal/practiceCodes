#pragma once

#include<iostream>
#include<string>
#include "Coffee.h"

using namespace std;

class Factory_Coffee {
public:
	Factory_Coffee() {
		
	}
	virtual Coffee* getCoffeeObject(string coffeeType, string coffeeName, int cupSize) = 0;
	virtual void displayFactory() = 0;
};

class Factory_Coffee_US : public Factory_Coffee {
public:
	Factory_Coffee_US();
	Coffee* getCoffeeObject(string coffeeType, string coffeeName, int cupSize) override;
	void displayFactory() override;
};

class Factory_Coffee_India : public Factory_Coffee {
public:
	Factory_Coffee_India();
	Coffee* getCoffeeObject(string coffeeType, string coffeeName, int cupSize) override;
	void displayFactory() override;
};

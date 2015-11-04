#pragma once
#include "FactoryCoffee.h"

Factory_Coffee_US::Factory_Coffee_US() {
	cout << "\n In the constructor of Factory USA Coffee Class";
}

Factory_Coffee_India::Factory_Coffee_India() {
	cout << "\n In the constructor of Factory India Coffee Class";
}

Coffee* Factory_Coffee_US::getCoffeeObject(string coffeeType, string coffeeName, int cupSize) {
	if (coffeeName == "mocha") {
		return new Mocha_USA(cupSize, coffeeType);
	}
	else if (coffeeName == "javachip") {
		return new JavaChip_USA(cupSize, coffeeType);
	}
	else {
		throw std::logic_error("invalid coffee Name!");
	}
}

Coffee* Factory_Coffee_India::getCoffeeObject(string coffeeType, string coffeeName, int cupSize) {
	if (coffeeName == "mocha") {
		return new Mocha_India(cupSize, coffeeType);
	}
	else if (coffeeName == "javachip") {
		return new JavaChip_India(cupSize, coffeeType);
	}
	else {
		throw std::logic_error("invalid coffee Name!");
	}
}

void Factory_Coffee_US::displayFactory() {
	cout << "Display of US Factory Class";
}

void Factory_Coffee_India::displayFactory() {
	cout << "Display of India Factory Class";
}


#include "FactoryCoffee.h"

Factory_Coffee::Factory_Coffee() {
	cout << "\n In the constructor of Factory Coffee";
}

Coffee* Factory_Coffee::getCoffeeObject(string coffeeType, string coffeeName, int cupSize) {
	if (coffeeName == "mocha") {
		return new Mocha(cupSize, coffeeType);
	}
	else if (coffeeName == "javachip") {
		return new JavaChip(cupSize, coffeeType);
	}
	else {
		throw std::logic_error("invalid coffee Name!");
	}
}
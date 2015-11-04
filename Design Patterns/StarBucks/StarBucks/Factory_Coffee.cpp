#include "Factory_Coffee.h"

Factory_Coffee::Factory_Coffee() {
	cout << "\n In the constructor of Factory Coffee";
}

Coffee* Factory_Coffee::getCoffeeObject(string coffeeType, string coffeeName, string cupSize) {
	if (coffeeType == "Hot") {
		return new HotCoffee(coffeeName, cupSize);
	}
	else if (coffeeType == "Cold") {
		return new ColdCoffee(coffeeName, cupSize);
	}
	else {
		throw std::logic_error("invalid coffee type");
	}
}
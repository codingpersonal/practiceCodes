#include"FactoryController.h"

FactoryController::FactoryController() {
	cout << "In the Factory Controller Class Constructor";
}

Factory_Coffee* FactoryController::chooseFactoryClass(string country) {
	if (country == "India") {
		return new Factory_Coffee_India();
	}
	else
		return new Factory_Coffee_US();
}
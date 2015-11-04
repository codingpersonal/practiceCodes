#include "CoffeeOrder.h"
#include <iostream>
#include<string>

using namespace std;

CoffeeOrder::CoffeeOrder(Coffee *c_obj) :cobj_(c_obj) {
	cout << "\nIn constructor of Coffee Order";
	coffeePrice = 0.0;
}

float CoffeeOrder::placeOrder(int cupSize, string coffeeType) {
	cout << "\nPlacing order for the customer's coffee";
	cobj_->prepareCoffee();
	cobj_->drinkCoffee();
	coffeePrice = cobj_->getPrice();

	return coffeePrice;
}
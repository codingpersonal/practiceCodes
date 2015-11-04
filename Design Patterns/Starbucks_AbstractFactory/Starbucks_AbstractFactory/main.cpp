#include "CoffeeOrder.h"
#include "FactoryController.h"
#include<iostream>
#include<string>

using namespace std;

int main() {

	Coffee *c_obj;

	string coffeeType;
	cout << "Enter the type of coffee you want - Hot/Cold:";
	cin >> coffeeType;

	string coffeeName;
	cout << "\nEnter the coffee Name:";
	cin >> coffeeName;

	int cupSize;
	cout << "\nEnter cup size(1: Tall, 2: grande, 3: Large) :";
	cin >> cupSize;

	float price;
	string country = "India";

	FactoryController fc_obj;
	Factory_Coffee *f_obj;

	f_obj = fc_obj.chooseFactoryClass(country);
	c_obj = f_obj->getCoffeeObject(coffeeType, coffeeName, cupSize);

	CoffeeOrder co(c_obj);
	price = co.placeOrder(cupSize, coffeeType);
	cout << "\nPlease pay at counter:" << price;

	return 0;
}
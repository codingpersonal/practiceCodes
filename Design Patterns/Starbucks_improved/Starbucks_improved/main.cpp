#include "CoffeeOrder.h"
#include "FactoryCoffee.h"
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

	Factory_Coffee fc_obj;
	c_obj = fc_obj.getCoffeeObject(coffeeType, coffeeName, cupSize);

	CoffeeOrder co(c_obj);
	price = co.placeOrder(cupSize, coffeeType);
	cout << "\nPlease pay at counter:" << price;

	return 0;
}
#include "CoffeeOrder.h"
#include "Factory_Coffee.h"
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

	string cupSize;
	cout << "\nEnter cup size:";
	cin >> cupSize;

	float price;

	Factory_Coffee fc_obj;
	c_obj = fc_obj.getCoffeeObject(coffeeType,coffeeName, cupSize);

	CoffeeOrder co(c_obj);
	price = co.placeOrder(coffeeName,cupSize);
	cout << "\nPlease pay at counter:" << price;

	return 0;
}
#include "Coffee.h"
#include<iostream>

using namespace std;

HotCoffee::HotCoffee(string coffeeName, string cupSize):Coffee(coffeeName, cupSize) {
	cout << "\nIn Hot coffee class constructor:";
}

void HotCoffee::drinkCoffee() {
	cout << "\nDrinking Hot Coffee!";
}

void HotCoffee::prepareCoffee() {
	cout << "\nPreparing your hot " << coffeeName_;
}

float HotCoffee::getPrice() {
	if (coffeeName_ == "Mocha")
		return 3.75;
	else
		return 2.50;
}

ColdCoffee::ColdCoffee(string coffeeName, string cupSize) :Coffee(coffeeName, cupSize) {
	cout << "\nIn Cold coffee class constructor:";
}

void ColdCoffee::drinkCoffee() {
	cout << "\nDrinking Cold Coffee!";
}

void ColdCoffee::prepareCoffee() {
	cout << "\nPreparing your cold " << coffeeName_;
}

float ColdCoffee::getPrice() {
	if (coffeeName_ == "JavaChip")
		return 4.15;
	else
		return 3.90;
}
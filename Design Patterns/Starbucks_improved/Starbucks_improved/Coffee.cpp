#include "Coffee.h"
#include<iostream>

using namespace std;

Mocha::Mocha(int cupSize, string coffeeType) :Coffee(cupSize, coffeeType) {
	cout << "\nIn Mocha coffee class constructor:";
}

void Mocha::drinkCoffee() {
	cout << "\nDrinking "<<coffeeType_<<" Mocha Coffee!";
}

void Mocha::prepareCoffee() {
	cout << "\nPreparing " << coffeeType_ << " Mocha Coffee!";
}

float Mocha::getPrice() {
	if (coffeeType_ == "Hot")
		return hot_price[cupSize_ - 1];
	else
		return cold_price[cupSize_ - 1];
}

JavaChip::JavaChip(int cupSize, string coffeeType) :Coffee(cupSize, coffeeType) {
	cout << "\nIn JavaChip coffee class constructor:";
}

void JavaChip::drinkCoffee() {
	cout << "\nDrinking "<<coffeeType_<<" Javachip coffee";
}

void JavaChip::prepareCoffee() {
	cout << "\nPreparing " << coffeeType_ << " Javachip coffee";
}

float JavaChip::getPrice() {
	if (coffeeType_ == "Hot")
		return hot_price[cupSize_ - 1];
	else
		return cold_price[cupSize_ - 1];
}
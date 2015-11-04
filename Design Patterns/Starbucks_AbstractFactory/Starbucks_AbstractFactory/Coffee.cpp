#include "Coffee.h"
#include<iostream>

using namespace std;

Mocha_USA::Mocha_USA(int cupSize, string coffeeType) :Coffee(cupSize, coffeeType) {
	cout << "\nIn Mocha USA coffee class constructor:";
}

void Mocha_USA::drinkCoffee() {
	cout << "\nDrinking "<<coffeeType_<<" Mocha Coffee in USA!";
}

void Mocha_USA::prepareCoffee() {
	cout << "\nPreparing " << coffeeType_ << " Mocha Coffee in USA!";
}

float Mocha_USA::getPrice() {
	if (coffeeType_ == "Hot")
		return hot_price[cupSize_ - 1];
	else
		return cold_price[cupSize_ - 1];
}

Mocha_India::Mocha_India(int cupSize, string coffeeType) :Coffee(cupSize, coffeeType) {
	cout << "\nIn Mocha India coffee class constructor:";
}

void Mocha_India::drinkCoffee() {
	cout << "\nDrinking " << coffeeType_ << " Mocha Coffee in India!";
}

void Mocha_India::prepareCoffee() {
	cout << "\nPreparing " << coffeeType_ << " Mocha Coffee in India!";
}

float Mocha_India::getPrice() {
	if (coffeeType_ == "Hot")
		return hot_price[cupSize_ - 1];
	else
		return cold_price[cupSize_ - 1];
}

JavaChip_USA::JavaChip_USA(int cupSize, string coffeeType) :Coffee(cupSize, coffeeType) {
	cout << "\nIn JavaChip USA coffee class constructor:";
}

void JavaChip_USA::drinkCoffee() {
	cout << "\nDrinking "<<coffeeType_<<" Javachip coffee in USA";
}

void JavaChip_USA::prepareCoffee() {
	cout << "\nPreparing " << coffeeType_ << " Javachip coffee in USA";
}

float JavaChip_USA::getPrice() {
	if (coffeeType_ == "Hot")
		return hot_price[cupSize_ - 1];
	else
		return cold_price[cupSize_ - 1];
}


JavaChip_India::JavaChip_India(int cupSize, string coffeeType) :Coffee(cupSize, coffeeType) {
	cout << "\nIn JavaChip India coffee class constructor:";
}

void JavaChip_India::drinkCoffee() {
	cout << "\nDrinking " << coffeeType_ << " Javachip coffee in India";
}

void JavaChip_India::prepareCoffee() {
	cout << "\nPreparing " << coffeeType_ << " Javachip coffee in India";
}

float JavaChip_India::getPrice() {
	if (coffeeType_ == "Hot")
		return hot_price[cupSize_ - 1];
	else
		return cold_price[cupSize_ - 1];
}
#pragma once
#pragma once
#include<string>

using namespace std;

class Coffee {
private:
protected:
	int cupSize_;
	string coffeeType_;
public:
	Coffee(int cupSize, string coffeeType) : cupSize_(cupSize), coffeeType_(coffeeType) {
	}
	virtual void prepareCoffee() = 0;
	virtual void drinkCoffee() = 0;
	virtual float getPrice() = 0;
};

class JavaChip : public Coffee {
private:
	const double cold_price[3] = { 2.45, 3.50, 4.80 };
	const double hot_price[3] = { 2.5, 3.45, 4.10 };
public:
	JavaChip(int cupSize, string coffeeType);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};

class Mocha : public Coffee {
private:
	const double cold_price[3] = { 2.10, 3.20, 4.30 };
	const double hot_price[3] = { 2.15, 3.60, 4.70 };
public:
	Mocha(int cupSize, string coffeeType);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};







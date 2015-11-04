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

class JavaChip_USA : public Coffee {
private:
	const double cold_price[3] = { 2.45, 3.50, 4.80 };
	const double hot_price[3] = { 2.5, 3.45, 4.10 };
public:
	JavaChip_USA(int cupSize, string coffeeType);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};

class JavaChip_India : public Coffee {
private:
	const double cold_price[3] = { 400, 500, 600 };
	const double hot_price[3] = { 440, 550, 660 };
public:
	JavaChip_India(int cupSize, string coffeeType);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};

class Mocha_USA : public Coffee {
private:
	const double cold_price[3] = { 2.10, 3.20, 4.30 };
	const double hot_price[3] = { 2.15, 3.60, 4.70 };
public:
	Mocha_USA(int cupSize, string coffeeType);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};

class Mocha_India : public Coffee {
private:
	const double cold_price[3] = { 100, 200, 300 };
	const double hot_price[3] = { 110, 220, 330 };
public:
	Mocha_India(int cupSize, string coffeeType);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};






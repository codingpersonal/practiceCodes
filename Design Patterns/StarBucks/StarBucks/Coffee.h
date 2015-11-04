#pragma once
#include<string>

using namespace std;

class Coffee {
private:
protected:
	string coffeeName_;
	string cupSize_;
public:
	Coffee(std::string coffeeName, string cupSize) : coffeeName_(coffeeName), cupSize_(cupSize) {
	}
	virtual void prepareCoffee() = 0;
	virtual void drinkCoffee() = 0;
	virtual float getPrice() = 0;
};

class ColdCoffee : public Coffee {
private:
public:
	ColdCoffee(string coffeeName, string cupSize);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};

class HotCoffee : public Coffee {
private:
public:
	HotCoffee(string coffeeName, string cupSize);
	void prepareCoffee() override;
	void drinkCoffee() override;
	float getPrice() override;
};







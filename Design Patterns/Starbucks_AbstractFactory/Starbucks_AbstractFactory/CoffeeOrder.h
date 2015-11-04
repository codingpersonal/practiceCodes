#pragma once

#include"Coffee.h"

class CoffeeOrder {
private:
	Coffee *cobj_;
	float coffeePrice;
public:
	CoffeeOrder(Coffee *c_obj);
	float placeOrder(int cupSize, string coffeeType);
};

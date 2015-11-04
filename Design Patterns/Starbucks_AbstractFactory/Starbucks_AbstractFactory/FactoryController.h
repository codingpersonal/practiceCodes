#pragma once
#include"FactoryCoffee.h"
#include<string>

class FactoryController {
public: 
	FactoryController();
	Factory_Coffee* chooseFactoryClass(string country);
};
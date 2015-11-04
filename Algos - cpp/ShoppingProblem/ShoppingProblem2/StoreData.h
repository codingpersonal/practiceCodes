#pragma once

#include <string>
#include <map>

struct storeData
{
	int id;
	std::string storeName;
	int xCoord;
	int yCoord;
	std::map<std::string,int> itemNamePriceMap;
};

#ifndef cheapItem_H
#define cheapItem_H

using namespace std;

#include<vector>
#include<map>
#include<set>
#include<iostream>
#include<string>
#include <vector>
#include "StoreData.h"

using namespace std;


class BestRouteFinder
{
public:
	BestRouteFinder(vector<storeData> storesInfo);

	//returns the best path in the form of store ids. the store ids are in the returned vector is best route order
	void getBestRouteForItems(vector<string> itemList);
	
	~BestRouteFinder();

private:
	//This stores the objects of struture with all the store information from the file
	vector<storeData> storesInfo;

	set <int> visitingStoreId;

	//This map store the store id and object to the strcuture with the store details
	std::map<int,storeData> stores;

	//This maps the item name to store id which is having the minimum price for the item for all the items available from all the stores
	std::map<string,int> itemMinPriceStore;

	//This function returns the total price 
	int calculatePrice(vector<string> itemList);

	//generates a set of stores which the user will eventually visit
	int* populateVisitingStoreList(vector<string> itemList);

	//populates the itemMinPriceStore Map
	void populateLowestPriceItemMap();

};

#endif
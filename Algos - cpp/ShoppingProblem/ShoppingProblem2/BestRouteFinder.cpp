#include "BestRouteFinder.h"
#include "ShortestDistance.h"
#include "StoreInfoFileParser.h"
#include <set>

BestRouteFinder::BestRouteFinder(vector<storeData> inStoresInfo):storesInfo(inStoresInfo)
{
	int id;
	for(int i = 0; i < storesInfo.size(); i++)
	{
		id = storesInfo[i].id;
		stores[id] = storesInfo[i];
	}

	populateLowestPriceItemMap();

}

//returns the best path in the form of store ids. the store ids are in the returned vector is best route order
void BestRouteFinder::getBestRouteForItems(vector<string> itemList) 
{
	int totPrice = 0;
	int *seq;

	seq = populateVisitingStoreList(itemList);

	//calculate the total price here
	totPrice = calculatePrice(itemList);
	cout<<"\ntotal price of items are: "<<totPrice;

	map<int, coord> c;
	coord localC;
	for(int i=0; i < visitingStoreId.size(); i++) {
		localC.xc = stores[seq[i]].xCoord;
		localC.yc = stores[seq[i]].yCoord;
		c[seq[i]] = localC;
	}

	//create an object of shortest distance class
	ShortestDistance s_obj(visitingStoreId.size(), c);
	//generate the sequences from the input
	s_obj.generateSeq(seq, 0, visitingStoreId.size());
	//Analyse the sequences and find the shortest distance and min route sequence
	s_obj.checkSeqAndFindShortest();

	s_obj.printShortestDistance();
}

void BestRouteFinder::populateLowestPriceItemMap() {

	for(int i=0; i < stores.size(); i++) {
		storeData currStore = stores[i];

		//get all items list
		map<string, int>::const_iterator itr = currStore.itemNamePriceMap.begin();
		while(itr != currStore.itemNamePriceMap.end()) {

			string itemName = itr->first;

			//check if item has been accessed earlier
			if(itemMinPriceStore.count(itemName) == 0) {

				itemMinPriceStore[itemName] = currStore.id;

			} else {
	
				//compare prices
				int old_price_store_id = itemMinPriceStore[itemName];
				int old_price = stores[old_price_store_id].itemNamePriceMap[itemName];

				if(old_price > itr->second) {
					itemMinPriceStore[itemName] = currStore.id;
				}
			}
			itr++;
		}
	}
}

int BestRouteFinder::calculatePrice(vector <string> itemList)
{
	int totPrice = 0;
	string itemName;
	int cheapStoreId;

	for(int index = 0; index < itemList.size(); index++)
	{
		itemName = itemList[index];

		//check if item is present
		if(itemMinPriceStore.count(itemList[index]) > 0) 
		{
			cheapStoreId = itemMinPriceStore[itemName];
			totPrice += stores[cheapStoreId].itemNamePriceMap[itemName];
		}
	}

	return totPrice;
}

int* BestRouteFinder::populateVisitingStoreList(vector <string> itemList)
{
	string itemName;
	int cheapStoreId;
	visitingStoreId.clear();

	for(int index = 0; index < itemList.size(); index++)
	{
		itemName = itemList[index];
		cheapStoreId = itemMinPriceStore[itemName];
		visitingStoreId.insert(cheapStoreId);
	}

	//Copy this set into the seq which is to be sent to generate sequence
	int *seq = new int[visitingStoreId.size()];
	std::set<int>::const_iterator it=visitingStoreId.begin();

	for(int i = 0; i < visitingStoreId.size(); i++)
	{
		seq[i] = (*it);
		it++;
	}

	return seq;
}

BestRouteFinder::~BestRouteFinder() 
{

}

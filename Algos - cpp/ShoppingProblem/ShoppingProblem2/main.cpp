#include "FileUtils.h"
#include "ShortestDistance.h"
#include "BestRouteFinder.h"
#include "FileUtils.h"
#include "StoreInfoFileParser.h"
#include "StoreData.h"

int main()
{
	string currline;
	FileUtils f_obj("C:\\Users\\somya\\Downloads\\ip.txt");

	vector <string> itemList;
	vector <storeData> storeObj;

	StoreInfoFileParser si("C:\\Users\\somya\\Downloads\\input.txt");
	si.getStoreInfo(storeObj);
	BestRouteFinder b_obj(storeObj);

	while(f_obj.readNextLine(currline))
	{
		itemList.push_back(currline);
	}

	b_obj.getBestRouteForItems(itemList);

	return 0;
}
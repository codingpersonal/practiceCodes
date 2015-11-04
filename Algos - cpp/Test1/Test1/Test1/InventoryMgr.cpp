using namespace std;
#include<iostream>

class InventoryMgr
{
	unsigned int count;
	unsigned long item[1000]; //This will run for 64000 items in the inventory
public:
	InventoryMgr()
	{
		count = 64000;
		long max = (1 << 63);
		max -= 1;
		max = max | (1 << 63);

		for(int index = 0; index < 1000; index ++)
		{
			item[index] = max;	
		}
	}

	void getIndex(int *arrayIndex, int *bitIndex, int itemNo)
	{
		*arrayIndex = itemNo / 64;
		*bitIndex = itemNo % 64;

		//cout<<*arrayIndex<<" "<<*bitIndex;
	}
	
	bool checkBit(int arrayIndex, int bitIndex)
	{
		return((item[arrayIndex] >> bitIndex) & 1);
	}

	void markItemOutOfStock(int itemNo)
	{
		int arrayIndex, bitIndex;
		getIndex(&arrayIndex, &bitIndex, itemNo);

		bool check = checkBit(arrayIndex, bitIndex);
		if(check)
		{
			long setPos = ~(1<<bitIndex);
			item[arrayIndex] = item[arrayIndex] & setPos;
			count -= 1;
		}
	}

	void markItemInStock(int itemNo)
	{
		int arrayIndex, bitIndex;
		getIndex(&arrayIndex, &bitIndex, itemNo);
		
		bool check = checkBit(arrayIndex, bitIndex);
		if(!check)
		{
			long setPos = 1<<bitIndex;
			item[arrayIndex] = item[arrayIndex] | setPos;
			count += 1;
		}
	}

	void isItemInStock(int itemNo)
	{
		int arrayIndex, bitIndex;
		getIndex(&arrayIndex, &bitIndex, itemNo);

		bool check = checkBit(arrayIndex, bitIndex);
		if(check)
			cout<<"\nItem is in stock";
		else
			cout<<"\nItem is out of stock";
	}

	int countNoOfItemsInStock()
	{
		return count;
	}
};

int main_IM()
{
	InventoryMgr obj;

	obj.markItemOutOfStock(0);
	obj.markItemOutOfStock(63);
	obj.markItemOutOfStock(64);
	obj.markItemOutOfStock(12345);
	obj.markItemOutOfStock(63999);

	int count = obj.countNoOfItemsInStock();
	cout<<"\nItems in stock is:"<<count;

	obj.isItemInStock(0);
	obj.isItemInStock(63);
	obj.isItemInStock(64);
	obj.isItemInStock(12345);
	obj.isItemInStock(999);
	obj.isItemInStock(63999);

	//cout<<obj.checkBit(999, 63);

	obj.markItemInStock(12345);
	obj.markItemInStock(999);
	obj.markItemInStock(63999);

	count = obj.countNoOfItemsInStock();
	cout<<"\nItems in stock is:"<<count;

	cout<<"\n";
	return 0;
}
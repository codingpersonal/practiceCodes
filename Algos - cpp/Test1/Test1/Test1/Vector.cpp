using namespace std;
#include<iostream>

class vector
{
private:

	int *vecArr;
	unsigned int totalVectorsize;
	unsigned int currentVectorSize;

public:

	vector()
	{
		totalVectorsize = 10;
		currentVectorSize = 0;

		vecArr = new int[10];
	}

	void allocateMoreAndCopy()
	{
		int newSize = totalVectorsize * 2;
		int *newVecArr = new int[newSize];
		int index;

		for(index = 0; index < totalVectorsize; index++)
		{
			newVecArr[index] = vecArr[index];
		}

		delete vecArr;

		vecArr = newVecArr;
		totalVectorsize = newSize;

	}

	void pushback(unsigned int value)
	{

		if(currentVectorSize >= totalVectorsize)
		{
			allocateMoreAndCopy();
		}

		vecArr[currentVectorSize] = value;
		currentVectorSize++;
	}

	//This function gives the current Array Size
	int getSize()
	{
		return currentVectorSize;
	}

	void resetAll()
	{
		int currentSize = getSize();

		cout<<"\nResetting all the elements of the vector!";
		for(int index = 0; index < currentSize; index++)
		{
			vecArr[index] = -1;
		}

		currentVectorSize = 0;
	}

	void deleteAnElement(int pos)
	{
		int size = getSize();

		if(pos > size)
		{
			cout<<"\nInvalid position!";
			return;
		}
		for(int index = pos - 1; index < size; index++)
		{
			vecArr[index] = vecArr[index + 1];
		}

		currentVectorSize--;
	}

	void printTotalVectorSize()
	{
		cout<<"\nThe total vector size for which the memory has been allocated is:"<<totalVectorsize;
	}

	void printVectorElements()
	{
		int size = getSize();
		cout<<"\nVector Array elements are:";
		for(int index = 0; index < size; index++)
		{
			cout<<vecArr[index]<<" ";
		}
	}
};

int main_vector()
{
	vector obj;

	for(int index = 0; index <= 19; index++)
	{
		obj.pushback(index);
	}

	obj.pushback(21);
	
	int  currentSize = obj.getSize();
	cout<<"\nCurrent vector size i.e. number of elements in it is:"<<currentSize;

	obj.printTotalVectorSize();
	obj.printVectorElements();

	cout<<"\n";
	return 0;
}
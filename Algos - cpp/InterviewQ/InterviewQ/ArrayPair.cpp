//There is an array of n numbers {5,4,0,9,3,2} and a number given by the user say 9
//Find out all the unique pairs from the array whose sum is equal to k
//So pairs are {5,4} {0,9}. Output only unique pairs. Do it in O(n) time complexity

#include<iostream>
#include<unordered_set>
#include<map>

using namespace std;

void main_q1()
{
	int size;
	int sum, currNum;
	unordered_set<int>arrElem;
	map<int,int>pairs;

	cout<<"\nEnter the size of an array:";
	cin>>size;

	int *arr = new int[size];
	cout<<"\nEnter elements of the array:";
	for(int index = 0; index < size; index++)
	{
		cin>>arr[index];
		arrElem.insert(arr[index]);
	}
	cout<<"\nEnter the number whose pair-sum needs to be located in array:";
	cin>>sum;
	
	cout<<"\nArray entered by the user is:";
	for(int index = 0; index < size; index++)
		cout<<arr[index]<<" ";

	unordered_set<int>::iterator it = arrElem.begin();
	while(it != arrElem.end())
	{
		currNum = sum - (*it);
		unordered_set <int>::const_iterator find = arrElem.find(currNum);
		if(find != arrElem.end())
		{
			//putting the values in the map such that the smaller number is the key.
			//This way values will not be duplicated.
		
			if(*it < currNum)
				pairs[*it] = currNum;
			else
				pairs[currNum] = *it;
		}

		it++;
	}
	
	//printing the pairs now here
	cout<<"\nPairs are:";
	map<int,int>::iterator iter = pairs.begin();
	while(iter != pairs.end())
	{
		cout<<iter->first<<" "<<iter->second<<"\n";
		iter++;
	}

	delete [] arr;
}
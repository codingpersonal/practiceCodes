#include"ShortestDistance.h"
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

ShortestDistance::ShortestDistance()
{
}

void ShortestDistance::popAdjListMap(vector<int> &fileInfo)
{
	vector<int> temp;
	for(int index = 1; index < fileInfo.size(); index++)
	{
		temp.push_back(fileInfo[index]);
	}

	AdjList[fileInfo[0]] = temp;
}

int ShortestDistance::findDistance(int src,int des)
{
	if(src == des)
	{
		cout<<"\nSource and Destination are same!";
		return 0;
	}

	queue<int> currNodes;
	set<int>temp;
	vector<int>child;
	map<int,int>prevNode;
	int dis = 0;

	currNodes.push(src);
	temp.insert(src);

	while(!(currNodes.empty()))
	{
		int currNode = currNodes.front();

		//cout<<" -> "<< currNode;
		currNodes.pop();		

		if(currNode == des)
		{
			int temp = currNode;
			cout<<"\nDestination node reached";
			cout<<"\nPath is: "<<temp;

			while(temp != src)
			{
				cout<<" ->";
				cout<<prevNode[temp];
				temp = prevNode[temp];
				dis++;
			}
		}

		child = AdjList[currNode];

		for(int index = 0; index < child.size(); index++)
		{
			if(temp.count(child[index]) == 0)
			{
				currNodes.push(child[index]);
				temp.insert(child[index]);
				prevNode[child[index]] = currNode;
			}
		}
	}
	return dis;
}

ShortestDistance::~ShortestDistance()
{
}
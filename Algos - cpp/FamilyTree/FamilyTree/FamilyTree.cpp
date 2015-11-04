#include"FamilyTree.h"
#include <vector>
#include <iostream>
#include <map>
#include<queue>

using namespace std;

FamilyTree::FamilyTree()
{
}

int FamilyTree::getMaxLevelInFamilyHistory(int node)
{
	return(getAncestors(node) + getGeneration(node)) + 1;
}

int FamilyTree::getAncestors(int node)
{
	int maxCount = 0;
    vector<int>temp;

    temp = childToParent[node];

    if(!temp.empty())
    {
        int currCount;
        for(int index = 0; index < temp.size(); index++)
        {            
            // each parent node would return the maxAncestors from itself. 
            currCount = getAncestors(temp[index]) + 1;
            if(currCount > maxCount) {
                maxCount = currCount;
            }
        }
    }
    
    return maxCount;
    
}

int FamilyTree::getGeneration(int node)
{
    int maxCount = 0;
    vector<int>temp;

    temp = parentToChild[node];

    if(!temp.empty())
    {
        int currCount;
        for(int index = 0; index < temp.size(); index++)
        {
            //iterate over all child nodes to find the max depth. 
            
            // each child node would return the maxGeneration from itself. 
            currCount = getGeneration(temp[index]) + 1;
            if(currCount > maxCount) {
                maxCount = currCount;
            }
        }
    }
    
    return maxCount;
    
}

void FamilyTree::buildFamilyInfo(int child, int parent1, int parent2)
{
	//Creating map for child to parent here
	vector<int>parentVector;

	parentVector.push_back(parent1);
	parentVector.push_back(parent2);
	
	childToParent[child] = parentVector;

	//creating map for parent to child here
	parentVector.clear();

	parentVector = parentToChild[parent1];
	parentVector.push_back(child);
	parentToChild[parent1] = parentVector;

	parentVector.clear();
	parentVector = parentToChild[parent2];
	parentVector.push_back(child);
	parentToChild[parent2] = parentVector;
}

void FamilyTree::bfs(int node)
{
	queue<int> currNodes;
	set<int>temp;
	vector<int>child;

	currNodes.push(node);
	temp.insert(node);

	while(!(currNodes.empty()))
	{
		int currNode = currNodes.front();
		cout<<" -> "<< currNode;
		currNodes.pop();

		child = parentToChild[currNode];

		for(int index = 0; index < child.size(); index++)
		{
			if(temp.count(child[index]) == 0)
			{
				currNodes.push(child[index]);
				temp.insert(child[index]);
			}
		}
	}
}

FamilyTree::~FamilyTree()
{
}
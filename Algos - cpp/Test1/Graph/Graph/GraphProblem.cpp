#include "GraphProblem.h"
#include "FileUtils.h"

using namespace std;
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<set>

GraphProblem::GraphProblem(std::string inFileName)
{
	string currLine;
	FileUtils f_obj(inFileName);
	while(f_obj.readNextLine(currLine))
	{
		populateOutgoingNodeMap(currLine);
		populateIncomingNodeMap();
	}	
}

void GraphProblem::findTopNode()
{
	cout<<"\nNodes on which there are no incoming nodes are:";
	map<int,vector<int>> ::const_iterator it = outgoingEdges.begin();
	while(it != outgoingEdges.end())
	{
		if(incomingEdges.count(it->first) > 0)
		{
			//do nothing
		}
		else
		{
			cout<<it->first<<" ";
		}

		it++;
	}
}

void GraphProblem::findLastNode()
{
	cout<<"\nNodes which further do not depend on any node are:";
	map<int,set<int>>::const_iterator it = incomingEdges.begin();
	while(it != incomingEdges.end())
	{
		if(outgoingEdges[it->first].empty())
			cout<<it->first<<" ";
		it++;
	}
}

void GraphProblem::getNodeVectorFromFile(std::string line, std::vector<int> &outEdges)
{
	//parse and split the incoming line with ,
	size_t found;
	int len = line.size();
	int pos = 0;
	char buffer[20];
	size_t buf_size;

	do
	{
		found = splitByChar(line,',',pos);

		if(found > len)
			break;
		else
		{			
			buf_size = line.copy(buffer,found - pos,pos);
			buffer[buf_size] = '\0';
			outEdges.push_back(atoi(buffer));
		}
		pos = found + 1;

	}while(found != string::npos);

	buf_size = line.copy(buffer,len - pos,pos);
	buffer[buf_size] = '\0';
	outEdges.push_back(atoi(buffer));

}

void GraphProblem::populateOutgoingNodeMap(std::string line)
{
	int found = 0;

	//1:2,3 buffer will contain 1; buffer1 will contain 2,3 and buffer2 is a temp to contain 2 and 3
	char buffer[50],buffer1[50],buffer2[50];

	int buf_size;

	//will contain the nodes on rhs as read from the file
	vector <int> outEdges;

	//Split by :
	found = splitByChar(line,':',0);
	buf_size = line.copy(buffer,found,0);
	buffer[buf_size] = '\0';

	//Split the remaining line by , and keep pushing in a vector
	buf_size = line.copy(buffer1,line.size() - found,found + 1);
	buffer1[buf_size] = '\0';

	string temp(buffer1);
	
	//This will return the vector filled from the rhs nodes in a lines from the file
	getNodeVectorFromFile(temp,outEdges);

	outgoingEdges[atoi(buffer)] = outEdges;
}

size_t GraphProblem::splitByChar(std::string input, char c, int pos)
{
	size_t found = input.find(c,pos);
	return found;
}

GraphProblem::~GraphProblem()
{

}

void GraphProblem::populateIncomingNodeMap()
{
	int item;

	map<int, vector<int>>::iterator it=outgoingEdges.begin();
	while(it != outgoingEdges.end())
	{
		for(int i=0; i < it->second.size(); i++)
		{
			item = it->second[i];
			incomingEdges[item].insert(it->first);
		}
		it++;
	}
}

int GraphProblem::findDependencies(int node)
{
	if (totalDependencyEdges.count(node) > 0) {
		//we have already found that and is present in cache
		return totalDependencyEdges[node];
	}

	cout<<"\nFinding dependency for node:"<<node;
	//check if this is the leaf node
	int count = 0;

	if(!outgoingEdges[node].empty())	{
		for(int i=0; i<outgoingEdges[node].size(); i++)
		{
			//add the child of the child, +1 is done to add the child node itself.
			count += findDependencies(outgoingEdges[node][i]) + 1;
		}
	}

	totalDependencyEdges[node] = count;
	return count;
}

void GraphProblem::findDependencyCountOfAllNodes()
{
	int count = 0;
	map<int,vector<int>>::const_iterator it= outgoingEdges.begin();
	while(it != outgoingEdges.end())
	{
		count = findDependencies(it->first);
		cout<<"\n["<<it->first<<"] => "<<count;
		it++;
	}
}

void GraphProblem::printChildNodes(int node, set<int>&nodeList)
{
	if(nodeList.count(node) == 0)
	{
		if(outgoingEdges[node].empty())
		{
			cout<<" -> " <<node;
			nodeList.insert(node);
			return;
		}

		vector<int> temp = outgoingEdges[node];
		for(int index=0; index < temp.size(); index++)
		{
			printChildNodes(temp[index], nodeList);
		}

		cout<<" -> " <<node;
		nodeList.insert(node);
	}
}
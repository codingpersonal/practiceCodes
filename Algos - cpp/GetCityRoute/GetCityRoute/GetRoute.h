#include<map>
#include<set>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class GetRoute {
private:
	map<string,vector<string>> outgoingNode;
	
	vector<string> route;
	
	vector<string>visitedNodes;
public:
	GetRoute( map<string,vector<string>>& nodeMap);
	
	void findSingleRoute(string src, string des);
	
	void printSingleRoute();

	//contains all the loop nodes
	vector<vector<string>>nodesInCycle;
};
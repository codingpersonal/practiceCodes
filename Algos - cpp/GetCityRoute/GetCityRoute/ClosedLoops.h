#include<map>
#include<set>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class ClosedLoops {
private:
	map<string,vector<string>> outgoingNode;

	//contains the set of nodes only in current dfs traversal
	vector<string>visitedNodes;
	
	//is loop present
	bool isLoop;

	//no of loops present
	int loopCount;

	//contains all the loop nodes
	vector<vector<string>>nodesInCycle;
public:
	ClosedLoops( map<string,vector<string>>& nodeMap);
	void checkIfCycle(string src);
	void printIfCycle();
	void printNodesInCycle();
	bool returnTrueIfCycle();
};
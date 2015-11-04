#include<set>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class TopoSort {
private:
	map<string,vector<string>> outgoingNode;
	vector<string> TopoSortPath;
	set<string>visitedNodes_dfsChain;
	set<string>visitedNodes_gen;
public:
	TopoSort( map<string,vector<string>>& nodeMap);
	void findTopoSort_dag(string src);
	void printTopoSortResult();
};                                             
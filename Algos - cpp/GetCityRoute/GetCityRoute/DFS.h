#include "StoreGraphData.h"
#include<set>

class DFS {
private:
	map<string,vector<string>> outgoingNode;
	vector<string> dfsPath;
	set<string>visitedNodes;
public:
	DFS( map<string,vector<string>>& nodeMap);
	void findDFS(string src);
	void printDFS();
};                                             
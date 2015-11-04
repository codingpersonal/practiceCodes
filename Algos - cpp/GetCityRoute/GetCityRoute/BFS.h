#include<queue>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include <iostream>
#include<set>

using namespace std;

class BFS {
private:
	map<string,vector<string>> outgoingNode;
	queue<string> BFSqueue;
	set<string>outVisitedNodes;
	int distance;
public:
	BFS( map<string,vector<string>>& nodeMap);
	void findBFS(string src);
	void findShortestDistance(string src, string des);
};                                             
#include<set>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<queue>
#include<set>

using namespace std;

class ShortestDistance {
private:
	map<string, vector<string>> outgoingNode;
	map<string, int> disToDest;
	//int distance;
	queue <pair<string,int>> BFSqueue;
	set<string> outVisitedNodes;
	//set<pair<string, int>>outVisitedNodes_dp;

public:
	ShortestDistance(map<string, vector<string>>& nodeMap);
	void findShortestDis_dfs(string src, string des, int len);
	void printShortDis();

	int findShortestDis_dfs_1(string src, string des);

	void findShortestDis_dp(string src, string des);
	std::pair<int, int> findMinMaxDis_dfs(string src, string des);

	void findShortestDis_bfs(string src, string des);
	void findShortestDis_bfs_dp(string src, string des);
};
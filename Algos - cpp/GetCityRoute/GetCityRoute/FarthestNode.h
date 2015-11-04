#include<set>
#include<vector>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
#include<utility>

using namespace std;

class FarthestNode {
private:
	map<string,vector<string>> outgoingNode;
	int outD;
	string outN;
	map<string,pair<string,int>>farNodeToDis;
	int distance;
public:
	FarthestNode( map<string,vector<string>>& nodeMap);
	void findFarthestNode(string src, int distance);
	//find farthest node using dynamic prog; optimised solution
	void findFarthestNode_dp(string src);
	void findShortestDis(string src, string des, int len);
	void printResult();
	void printResult_dp(string src);
	void printShortDis();
};                                             
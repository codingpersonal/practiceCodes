#include "ShortestDistance.h"
#include <algorithm>

using namespace std;

ShortestDistance::ShortestDistance(map<string, vector<string>>& nodeMap) :outgoingNode(nodeMap) {
	distance = 9999;
}

// len is the length of current src w.r.t. original src
void ShortestDistance::findShortestDis_dfs(string src, string des, int len) {
	if (src == des) {
		distance = std::min(len, distance);
	}
	else {
		vector<string>& nodeList = outgoingNode[src];
		for (vector<string>::const_iterator id = nodeList.begin();
		id != nodeList.end(); id++) {
			findShortestDis_dfs(*id, des, len + 1);
		}
	}
}

// it will return the shortest distance from src to the des
int ShortestDistance::findShortestDis_dfs_1(string src, string des) {
	if (src == des) {
		return 0;
	}
	else {
		vector<string>& nodeList = outgoingNode[src];
		int len = 9999;
		int distance = 9999;
		for (vector<string>::const_iterator id = nodeList.begin(); id != nodeList.end(); id++) {
			len = findShortestDis_dfs_1(*id, des);
			distance = min(len, distance);
		}
		return distance + 1;
	}
}

// it will return a pair of min and max distance from src to des
std::pair<int, int> ShortestDistance::findMinMaxDis_dfs(string src, string des) {
	if (src == des) {
		return (make_pair(0, 0));
	}
	else {
		vector<string>& nodeList = outgoingNode[src];
		int minD = 9999;
		int maxD = -9999;
		for (vector<string>::const_iterator id = nodeList.begin(); id != nodeList.end(); id++) {
			pair<int, int> len = findMinMaxDis_dfs(*id, des);
			minD = min(len.first, minD);
			maxD = max(len.second, maxD);
		}
		return (make_pair(minD + 1,maxD + 1));
	}
}

void ShortestDistance::printShortDis() {
	cout << "Distance is:" << distance;
}

void ShortestDistance::findShortestDis_dp(string src, string des) {
	
}

void ShortestDistance::findShortestDis_bfs(string src, string des) {
	if (src == des) {
		cout << "Source and destination are same, so distance is 0";
		return;
	}

	BFSqueue.push(make_pair(src,0));
	
	while (BFSqueue.empty() != 1) {
		src = BFSqueue.front().first;

		vector<string>& nodeList = outgoingNode[src];
		for (vector<string>::const_iterator id = nodeList.begin(); id != nodeList.end(); id++) {
			if (*id != des) {
				BFSqueue.push(make_pair(*id, BFSqueue.front().second + 1));
			}
			else {
				distance = min(distance, BFSqueue.front().second + 1);
			}
		}
		BFSqueue.pop();
	}
}

int ShortestDistance::findShortestDis_bfs_dp(string src, string des) {
	int minDist = 0;

	BFSqueue.push(make_pair(src, 0));
	std::set<std::string> outVisitedNodes_dp;

	while (BFSqueue.empty() != 1) {
		auto p = BFSqueue.front();
		BFSqueue.pop();

		vector<string>& nodeList = outgoingNode[p.first];
		for (vector<string>::const_iterator id = nodeList.begin(); id != nodeList.end(); id++) {
			if (outVisitedNodes.count(*id) > 0)
				continue;

			if (*id != des) {
				BFSqueue.push(make_pair(*id, p.second + 1));
			}
			else {
				minDist = p.second;
				break;
			}
		}
		outVisitedNodes_dp.insert(src);
	}

	return minDist;
}








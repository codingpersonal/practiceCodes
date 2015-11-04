#include "BFS.h"
using namespace std;

BFS::BFS( map<string,vector<string>>& nodeMap):outgoingNode(nodeMap) {
	distance = 9999;
}

void BFS::findBFS(string src) {
	//when using find, try to do that in a set. Find operation in a vector is costly O(n)
	if(outVisitedNodes.find(src) == outVisitedNodes.end()) {
		BFSqueue.push(src);
		while(BFSqueue.empty() != 1) {
			src = BFSqueue.front();
			BFSqueue.pop();

			vector<string>& nodeList = outgoingNode[src];
			for(vector<string>::const_iterator id = nodeList.begin(); id != nodeList.end(); id++) {
				BFSqueue.push(*id);
			}

			cout<<src<<" ";
			outVisitedNodes.insert(src);
		}		
	}
}


void BFS::findShortestDistance(string src, string des) {
	int len = 0;
	BFSqueue.push(src);
	while(BFSqueue.empty() != 1) {
		if(src != des) {
			src = BFSqueue.front();
			BFSqueue.pop();
			vector<string>& nodeList = outgoingNode[src];
			for(vector<string>::const_iterator id = nodeList.begin(); id != nodeList.end(); id++) {
				BFSqueue.push(*id);
			}
			outVisitedNodes.insert(src);
		}		
		else {
			if(distance > len) 
				distance = len;
			cout<<"Shortest length is:"<<distance;
		}
	}
}
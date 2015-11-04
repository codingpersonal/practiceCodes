#include "DFS.h"

DFS::DFS( map<string,vector<string>>& nodeMap):outgoingNode(nodeMap) {
}

void DFS::findDFS(string src) {

	//If the node is not visited yet
	if(visitedNodes.count(src) == 0) {
		dfsPath.push_back(src);
		visitedNodes.insert(src);

		vector<string> nodeList;
		nodeList = outgoingNode[src];
		
		vector<string>::const_iterator id = nodeList.begin();
		while(id != nodeList.end()) {
			findDFS(*id);
			id++;
		}
	}	
}

void DFS::printDFS() {
	cout<<"\nDFS is:";
	vector<string>::const_iterator id = dfsPath.begin();
	while(id != dfsPath.end()) {
		cout<<*id<<" ";
		id++;
	}
}
#include "GetRoute.h"
#include<algorithm>

GetRoute::GetRoute( map<string,vector<string>>& nodeMap): outgoingNode(nodeMap) {
}

void GetRoute::findSingleRoute(string src, string des) {

	if((find(visitedNodes.begin(), visitedNodes.end(), src)!=visitedNodes.end()) == 0) {
		visitedNodes.push_back(src);

		//termination condition
		if(src == des) 
			nodesInCycle.push_back(visitedNodes);

		else {
			for(vector<string>::const_iterator it = outgoingNode[src].begin(); it != outgoingNode[src].end(); it++) 
				findSingleRoute(*it,des);
		}
		visitedNodes.pop_back();
	}
}

void GetRoute::printSingleRoute() {
	if(nodesInCycle.size() == 0) 
		cout<<"\nNo route exists from source to destination.";
	else 
		cout<<"\n"<<nodesInCycle.size()<<" routes exist from source to destination.\n";

	for(vector<vector<string>>::const_iterator it = nodesInCycle.begin(); it != nodesInCycle.end() ; it++) {
		for(vector<string>::const_iterator id = it->begin(); id != it->end(); id++) {
			cout<<*id<<" ";
		}
		cout<<"\n";
	}
}
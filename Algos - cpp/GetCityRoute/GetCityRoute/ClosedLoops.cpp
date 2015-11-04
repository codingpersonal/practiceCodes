#include "ClosedLoops.h"
#include<algorithm>

ClosedLoops::ClosedLoops( map<string,vector<string>>& nodeMap):outgoingNode(nodeMap) {
	isLoop = false;
	loopCount = 0;
}

void ClosedLoops::checkIfCycle(string src) {

	//If the node is not visited yet
	if((find(visitedNodes.begin(), visitedNodes.end(), src)!=visitedNodes.end()) == 0) {
		visitedNodes.push_back(src);

		vector<string> nodeList;
		nodeList = outgoingNode[src];
		
		vector<string>::const_iterator id = nodeList.begin();
	
		while(id != nodeList.end()) {
			checkIfCycle(*id);
			id++;
		}
		//processing for this node is done. Now pop it out so that visited nodes only contain the current nodes in the dfs traversal
		visitedNodes.pop_back();
	}	

	else {
		isLoop = true;
		loopCount++;

		//visited nodes contain the nodes in the current dfs traversal from the beginning.
		//your loop may be a sub-loop of this traversal
		//extract from the src - current node till the end from the visited nodes vector.
		vector<string>tempvec;
		
		vector<string>::iterator it;
		it = find(visitedNodes.begin(),visitedNodes.end(),src);
		int pos = distance(visitedNodes.begin(), it);
		int size = visitedNodes.size();

		while(pos < size) {
			tempvec.push_back(visitedNodes[pos]);
			pos++;
		}

		nodesInCycle.push_back(tempvec);
	}
}

void ClosedLoops::printNodesInCycle() {
	vector<vector<string>>::const_iterator it = nodesInCycle.begin();
	while(it != nodesInCycle.end()){
		vector<string> temp = *it;
		vector<string>::const_iterator id = temp.begin();
		while(id != temp.end()) {
			cout<<*id<<" ";
			id++;
		}
		cout<<"\n";
		it++;
	}
	
}

void ClosedLoops::printIfCycle() {
	if(isLoop)
		cout<<"\nGraph contains Loop:"<<loopCount;
	else
		cout<<"\nGraph does not contain a loop, loopcount:"<<loopCount;
}

bool ClosedLoops::returnTrueIfCycle() {
	if(nodesInCycle.size() == 0)
		return false;
	else
		return true;
}
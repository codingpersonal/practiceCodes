#include "FarthestNode.h"

FarthestNode::FarthestNode( map<string,vector<string>>& nodeMap):outgoingNode(nodeMap) {
	outD = 0;
	distance = 9999;
}

void FarthestNode::findFarthestNode(string src, int distance) {
	vector<string>& nodeList = outgoingNode[src];
	for(vector<string>::const_iterator id = nodeList.begin(); 
		id != nodeList.end() ; id++) {
			distance++;
			findFarthestNode(*id, distance);

			if(outD < distance) {
				outD = distance;
				outN = *id;
			}
	}
}	

void FarthestNode::findFarthestNode_dp(string src) {
	int maxD = -1;
	string maxN = src;

	if(farNodeToDis.count(src) == 0) {
		vector<string>& nodeList = outgoingNode[src];
		for(vector<string>::const_iterator id = nodeList.begin(); 
			id != nodeList.end() ; id++) {
				findFarthestNode_dp(*id);
				if(maxD < farNodeToDis[*id].second) {
					maxD = farNodeToDis[*id].second;
					maxN = farNodeToDis[*id].first;
				}
		}
		farNodeToDis[src].first = maxN;
		farNodeToDis[src].second = maxD + 1;
	}
}

void FarthestNode::printResult() {
	cout<<"Node:"<<outN<<" is at a distance of "<<outD<<" from given node";
}

void FarthestNode::printResult_dp(string src) {
	cout<<"Node:"<<farNodeToDis[src].first<<" is at a distance of "<<farNodeToDis[src].second<<" from "<<src;
}


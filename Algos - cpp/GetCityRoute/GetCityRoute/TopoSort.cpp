#include "TopoSort.h"

TopoSort::TopoSort( map<string,vector<string>>& nodeMap):outgoingNode(nodeMap) {
}

//Visited nodes is keeping a track of all nodes that have been visited here.
//It not not storing the visited nodes in current dfs path here.
void TopoSort::findTopoSort_dag(string src) {
	//If the node is not visited yet
	if(visitedNodes_gen.count(src) == 0) {
		visitedNodes_gen.insert(src);
		vector<string> nodeList = outgoingNode[src];
		for(vector<string>::const_iterator id = nodeList.begin(); 
			id != nodeList.end() ; id++) {
				findTopoSort_dag(*id);
		}
		TopoSortPath.push_back(src);
	}	
}

void TopoSort::printTopoSortResult() {
	for(vector<string>::reverse_iterator rit = TopoSortPath.rbegin();
		rit != TopoSortPath.rend(); rit++) {
			cout<<*rit<<" ";
	}
}
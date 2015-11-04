#include "StoreGraphData.h"
using namespace std;


StoreGraphData::StoreGraphData(vector<string>& currLineDataFromFile): fileData(currLineDataFromFile) {
}

void StoreGraphData::fillOutgoingNodeMap( map<string,vector<string>>& outgoingNode) {
	vector<string>::const_iterator id = fileData.begin();
	vector<string> nodeList;
	
	string key = *id;
	id++;
	string val = *id;
	
	if(outgoingNode.count(key) > 0) {
		nodeList.empty();
		nodeList = outgoingNode.at(key);
		nodeList.push_back(val);
		outgoingNode[key] = nodeList;
	}
	else {
		nodeList.empty();
		nodeList.push_back(val);
		outgoingNode[key] = nodeList;
	}
		
}






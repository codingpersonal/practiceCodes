#include<string>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

class StoreGraphData {
public:
	StoreGraphData(vector<string>& currLineDataFromFile);

	//fills the mapping a-> if there is a node coming from a to b
	void fillOutgoingNodeMap( map<string,vector<string>> &outgoingNode);

private:
	vector<string> fileData;
};
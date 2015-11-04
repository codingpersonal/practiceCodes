#include "../../Common/FileParser/FileParser.h"
#include "DFS.h"
#include "BFS.h"
#include "TopoSort.h"
#include "GetRoute.h"
#include "ClosedLoops.h"
#include "FarthestNode.h"
#include "ShortestDistance.h"

using namespace std;

int main() {

	string currLine;
	string filePath = "E:\\cpp_learning\\GetCityRoute\\GetCityRoute\\TestFiles\\9.txt";
	vector<string> fileData;
	char delim = ':';
	map<string,string> incomingNode;
	map<string,vector<string>> outgoingNode;
	bool flag = 1;
	string src, des;

	FileReader fr(filePath);
	FileParser fp(filePath);

	while(fp.getNextLine(fileData,delim)) {
		StoreGraphData sobj(fileData);
		sobj.fillOutgoingNodeMap(outgoingNode);
		}
	
	/*cout<<"\nEnter source:";
	cin>>src;
	DFS dfs(outgoingNode);
	dfs.findDFS(src);
	dfs.printDFS();*/

	/*cout<<"\nEnter Source and destination:";
	cin>>src>>des;
	GetRoute gr(outgoingNode);
	gr.findSingleRoute(src,des);
	gr.printSingleRoute();*/
	
	/*cout<<"Enter source:";
	cin>>src;
	ClosedLoops cl(outgoingNode);
	cl.checkIfCycle(src);
	cl.printIfCycle();
	cl.printNodesInCycle();*/

	//Assume that input is a DAG. If its not then you need to check for cycles too in this code.
	/*TopoSort ts(outgoingNode);
	for(map<string,vector<string>>::const_iterator it = outgoingNode.begin(); 
		it != outgoingNode.end(); it++) {
				ts.findTopoSort_dag(it->first);
		}
	ts.printTopoSortResult();*/

	/*src = "1";
	int dis = 0;
	FarthestNode fn(outgoingNode);
	fn.findFarthestNode_dp(src);
	fn.printResult_dp(src);*/

	/*src = "1";
	int dis = 0;
	FarthestNode fn(outgoingNode);
	fn.findFarthestNode(src,0);
	fn.printResult();*/

	/*BFS b(outgoingNode);
	for(map<string,vector<string>>::const_iterator it = outgoingNode.begin(); 
		it != outgoingNode.end(); it++) {
			b.findBFS(it->first);
	}*/

	ShortestDistance b(outgoingNode);
	b.findShortestDis_bfs("1", "8");
	b.printShortDis();

	return 0;
}
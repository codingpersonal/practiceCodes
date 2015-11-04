#ifndef GraphProblem_H
#define GraphProblem_H

using namespace std;
#include<vector>
#include<map>
#include<string>
#include<set>

class GraphProblem
{
private:

	//map of the data as given in the file
	std::map <int,std::vector<int> > outgoingEdges;

	//maps an edge to the vector of edges which are depenedent on this edge.
	std::map <int,std::set<int> > incomingEdges;

	void populateIncomingNodeMap();

	//populates the map as given from data in the file
	void populateOutgoingNodeMap(std::string line);

	//splits the input using the character c from the pos
	size_t splitByChar(std::string input, char c, int pos);

	//used by populateOutgoingNodeMap to generate the vector after file parsing
	void getNodeVectorFromFile(std::string line, std::vector<int> &outEdges);

	//finds the number of nodes to which it should go to reach the leaf node.
	int findDependencies(int node);

	//dynamic map to keep a count of the outgoing edges from it. 
	// at any point, it may or may not have information.
	std::map<int,int>totalDependencyEdges;

public:
	GraphProblem(std::string inFileName);

	//finds the node on which no other node is dependent.
	void findTopNode();

	//find the node which is not dependent on further any node
	void findLastNode();

	//prints the child nodes all till the end for a given node
	void printChildNodes(int node,set<int>&nodeList);
	
	//finds the number of nodes to which it should go to reach the leaf node. Works for all nodes
	void GraphProblem::findDependencyCountOfAllNodes();

	~GraphProblem();
};

#endif
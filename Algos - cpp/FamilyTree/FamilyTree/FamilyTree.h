using namespace std;
#include<map>
#include<set>
#include<vector>

class FamilyTree
{
private:
	//This stores the mapping from the input file into the map.
	std::map <int,std::vector<int> > childToParent;

	std::map <int, vector<int> >parentToChild;
public:
	
	//this prints the nodes of the graph level-wise ie all immediate children first
	void FamilyTree::bfs(int node);

	//Finds the highest number of generation for a given node
	int getGeneration(int node);

	//gives the highest number of ancestors for a node in the family tree
	int getAncestors(int node);

	//gives the max level including child and parents for this node.
	int getMaxLevelInFamilyHistory(int node);

	//populates the parentChildMap as per information from the file.
	void buildFamilyInfo(int child, int parent1, int parent2);

	//Constructor for this class which takes in the vector of vector ints and poplulates the map
	FamilyTree();

	//Destructor for this class
	~FamilyTree();

};
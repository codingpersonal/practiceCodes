using namespace std;
#include<map>
#include<set>
#include<vector>

class ShortestDistance
{
private:
	//This stores the mapping from the input file into the map.
	std::map <int,std::vector<int> > AdjList;

public:
	
	//this prints the nodes of the graph level-wise ie all immediate children first
	int ShortestDistance::findDistance(int src, int des);
	
	//populates the AdjList as per information from the file.
	void popAdjListMap(vector<int> &fileInfo);

	//Constructor for this class which takes in the vector of vector ints and poplulates the map
	ShortestDistance();

	//Destructor for this class
	~ShortestDistance();

};
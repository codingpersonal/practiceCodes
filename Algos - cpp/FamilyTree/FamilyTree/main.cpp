#include "FileUtils.h"
#include"FamilyTree.h"
#include<iostream>
using namespace std;

int main()
{
    string filePath = "E:\\Learning\\C++\\FamilyTree\\FamilyTree.txt";
    FileUtils f_obj(filePath);

    FamilyTree tree_obj;

    string currLine;
    while(f_obj.readNextLine(currLine))
    {
        vector<int>lineInfo;
        
        f_obj.parseInputFile(currLine,lineInfo);

        // every line should have three ints
        if(lineInfo.size() != 3) {
            cout<<"invalid file, it should have 3 members";
            return -1;
        }        
  
        //this will keep on building the internal map      
        tree_obj.buildFamilyInfo(lineInfo[0], lineInfo[1], lineInfo[2]);
    }

	//Get  the max descdent for this node from the family tree
	int count = tree_obj.getGeneration(14);
	cout<<"Number of generations are:"<<count;
  
	count = tree_obj.getAncestors(7);
	cout<<"\n\nThe max number of ancestors for  node are:"<<count;
	
	count = tree_obj.getMaxLevelInFamilyHistory(2);
	cout<<"\n\nThe maximum number of levels (parent n child) in the family history for this node are:"<<count<<"\n";
	
	cout<<"\nBFS traversal of the graph is:"<<"\n";
	tree_obj.bfs(14);
    return 0;
}
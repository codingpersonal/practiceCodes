#include "FileUtils.h"
#include"ShortestDistance.h"
#include<iostream>
using namespace std;

int main()
{
    string filePath = "E:\\Learning\\C++\\Shortest_Distance_Graph\\Input.txt";
    FileUtils f_obj(filePath);

	ShortestDistance dis_obj;

    string currLine;
    while(f_obj.readNextLine(currLine))
    {
        vector<int>lineInfo;
        
        f_obj.parseInputFile(currLine,lineInfo);

        //this will keep on building the internal map      
		dis_obj.popAdjListMap(lineInfo);
    }

	int dis = dis_obj.findDistance(1,10);
	cout<<"\nTotal Distance is:"<<dis<<" units";
    return 0;
}
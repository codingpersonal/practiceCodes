#ifndef FileUtils_H
#define FileUtils_H

#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

class FileUtils
{
private:

	//splits the input string with the char c from the position pos
	size_t splitByChar(std::string input, char c, int pos);

	//Spilts the RHS of each line and fills it in the vector
	void getNodeVectorFromFile(std::string line, std::vector<int> &outEdges);

	string fileName; //FileName to be read 
	ifstream file;
	
public:
	FileUtils(string);

	//This function reads the input file and reads one line at a time
	bool readNextLine(string&);

	//This function parses one line of the input file and fills it in the vector
	void parseInputFile(string line, vector<int>&outEdges);
	
	~FileUtils();
};

#endif
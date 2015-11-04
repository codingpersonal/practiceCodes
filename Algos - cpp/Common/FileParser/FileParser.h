#include<iostream>
#include<string>
#include <vector>
#include"../FileReader/FileReader.h"
using namespace std;

//this parser returns the vector based on the char around which you want to split
class FileParser
{
public:
	FileParser(const string &inFilePath);

	//This function reads the Data file, parses it and stores the vector of string based on delim
	int getNextLine(vector<string>& fileFields, char delim);

private:
	FileReader _fu;

	//This function takes a string and splits it from the mentioned position by the character passed.
	size_t findDelimPos(string input, char delim, int pos);

	//Splits the line of the file using delim
	void splitLineByDelim(string currLine, vector<string>& fileFields, char delim);
};
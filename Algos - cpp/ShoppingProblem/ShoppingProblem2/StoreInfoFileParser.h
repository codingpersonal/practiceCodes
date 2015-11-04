#ifndef StoreInfoFileParser_H
#define StoreInfoFileParser_H
using namespace std;

#include<iostream>
#include<string>
#include <vector>
#include "StoreData.h"
#include "FileUtils.h"

//this parser knows the protocol of store info data in the given file
class StoreInfoFileParser
{
public:
	StoreInfoFileParser(string inFilePath);

	//This function reads the store Data file, parses it and fills the StoreData structure
	void getStoreInfo(vector<storeData> &outVector);

private:
	string filePath;

	//This function takes a string and splits it from the mentioned position by the character passed.
	size_t splitByChar(string input, char c, int pos);

	//This function takes an input a vector of strings splitted by '_', it further splits it for ':' and ',' and fills in the object of the storeData structure
	void StoreInfoFileParser::fillStoreData(const vector<string> &fileFields, storeData &f_obj, int id);

	//Splits the line of the file using '_' and calls to fillStoreData for further parsing and filling of storeData Structure
	void splitStoreData(string currLine,vector<string> &fileFields);
};

#endif
#ifndef FileUtils_H
#define FileUtils_H

#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class FileUtils
{
	string fileName; //FileName to be read 
	ifstream file;
	
public:
	FileUtils(string);

	//This function reads the input file and reads one line at a time
	bool readNextLine(string&);
	
	~FileUtils();
};

#endif
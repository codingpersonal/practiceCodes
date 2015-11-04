#ifndef FileReader_H
#define FileReader_H

#include<string>
#include<fstream>
#include<iostream>
using namespace std;

class FileReader
{
	string fileName; //FileName to be read 
	ifstream file;
	
public:
	FileReader(const string& fileName);

	//This function reads the input file and reads one line at a time
	bool readNextLine(string& currLine);
	
	~FileReader();
};

#endif
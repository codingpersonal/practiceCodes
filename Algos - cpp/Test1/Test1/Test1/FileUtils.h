#ifndef FileUtils_H
#define FileUtils_H

#include<string>
#include<fstream>

class FileUtils
{
	string fileName; //FileName to be read 
	ifstream file;
	
public:
	
	FileUtils(string):file(string), fileName(string);

	//This function reads the input file and reads one line at a time
	bool readNextLine(string);
	
	~FileUtils();
};

#endif
using namespace std;
#include "FileReader.h"

FileReader::FileReader(const string& inFileName):file(inFileName), fileName(inFileName)
{
}

bool FileReader::readNextLine(string &line)
{
	if(file.is_open())
	{
		if(getline(file,line))
			return true;
		else
			return false;
	}
	else
	{
		cout<<"\nError opening the file, cannot read this line!";
		return false;
	}
}

FileReader::~FileReader()
{
	file.close();
	cout<<"\nFile Closed!";
}


using namespace std;
#include"FileUtils.h"

FileUtils::FileUtils(string inFileName):file(inFileName), fileName(inFileName)
{
}

bool FileUtils::readNextLine(string &line)
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

FileUtils::~FileUtils()
{
	file.close();
}


#include "FileParser.h"
using namespace std;

FileParser::FileParser(const string& inFilePath):_fu(inFilePath) {
}

size_t FileParser::findDelimPos(string input, char delim, int pos)
{
	size_t found = input.find(delim,pos);
	return found;
}

int FileParser::getNextLine(vector<string>& fileFields, char delim)
{
	string currLine;

	if(_fu.readNextLine(currLine)) 
	{
		fileFields.clear();

		//Split the line read by the file using the needed delim
		splitLineByDelim(currLine,fileFields, delim);

		return 1;
	}
	else
		return 0;
}

void FileParser::splitLineByDelim(string currLine, vector<string>& fileFields, char delim)
{
	//parse and split each line
	size_t found;
	int len = currLine.size();
	int pos = 0;
	char buffer[20];
	size_t buf_size;

	do
	{
		found = findDelimPos(currLine,delim,pos);

		if(found > len)
			break;
		else
		{			
			buf_size = currLine.copy(buffer,found - pos,pos);
			buffer[buf_size] = '\0';
			fileFields.push_back(buffer);
		}
		pos = found + 1;

	}while(found != string::npos);

	buf_size = currLine.copy(buffer,len - pos,pos);
	buffer[buf_size] = '\0';
	fileFields.push_back(buffer);

}
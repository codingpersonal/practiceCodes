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

void FileUtils::parseInputFile(string line, vector<int>&outEdges)
{
	int found = 0;

	//1:2,3 buffer will contain 1; buffer1 will contain 2,3 and buffer2 is a temp to contain 2 and 3
	char buffer[50],buffer1[50],buffer2[50];

	int buf_size;

	//Split by :
	found = splitByChar(line,':',0);
	buf_size = line.copy(buffer,found,0);
	buffer[buf_size] = '\0';

	//Push the LHS in buffer
	outEdges.push_back(atoi(buffer));

	//Split the remaining line by , and keep pushing in a vector
	buf_size = line.copy(buffer1,line.size() - found,found + 1);
	buffer1[buf_size] = '\0';

	string temp(buffer1);
	
	//This will return the vector filled from the rhs nodes in a lines from the file
	getNodeVectorFromFile(temp,outEdges);

}

void FileUtils::getNodeVectorFromFile(std::string line, std::vector<int> &outEdges)
{
	//parse and split the incoming line with ,
	size_t found;
	int len = line.size();
	int pos = 0;
	char buffer[20];
	size_t buf_size;

	do
	{
		found = splitByChar(line,',',pos);

		if(found > len)
			break;
		else
		{			
			buf_size = line.copy(buffer,found - pos,pos);
			buffer[buf_size] = '\0';
			outEdges.push_back(atoi(buffer));
		}
		pos = found + 1;

	}while(found != string::npos);

	buf_size = line.copy(buffer,len - pos,pos);
	buffer[buf_size] = '\0';
	outEdges.push_back(atoi(buffer));

}

size_t FileUtils::splitByChar(std::string input, char c, int pos)
{
	size_t found = input.find(c,pos);
	return found;
}
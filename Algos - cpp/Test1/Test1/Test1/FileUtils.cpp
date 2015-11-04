using namespace std;
#include<iostream>
#include<fstream>
#include<string>

class FileUtils
{
	string fileName;
	ifstream file;
	
public:
	
	FileUtils(string inFileName):file(inFileName), fileName(inFileName)
	{
	}

	bool readNextLine(string &line)
	{
		if(file.is_open())
		{
			getline(file,line);
			return !file.badbit;
		}
		else
		{
			cout<<"\nError opening the file, cannot read this line!";
			return false;
		}
	}

	~FileUtils()
	{
		file.close();
		cout<<"\nFile Closed!";
	}
};

int main_file()
{
	string line;
	FileUtils f_obj("C:\\Users\\somya\\Downloads\\input.txt");
	f_obj.readNextLine(line);
	cout<<line;

	return 0;
}
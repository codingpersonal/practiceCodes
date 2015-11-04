#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FileUtils
{
	string fileName; //FileName to be read 
	ifstream file;
	
public:
	FileUtils(string);

	//This function reads the input file and reads one line at a time
	bool readNextLine(string&);

	//read word by word from the input file
	bool readNextWord(string &word, int &totalWordsCount);

	//returns the total number of words from a file
	int getTotalWordCount();

	//filter the input word and remove the non alphanumeric chars
	void removeNonAlphaNumChars(string &word);

	void convertToLower(string &word);
	
	~FileUtils();
};
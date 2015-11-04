using namespace std;
#include"FileUtils.h"
#include<algorithm>
#include<iostream>
#include<string>

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

bool FileUtils::readNextWord(string &word, int &totalWordsCount)
{
	if(file.is_open())
	{
		if(file >> word){
			totalWordsCount++;
			return true;
		}
		else
			return false;
	}
	else
	{
		cout<<"\nError opening the file!";
		return false;
	}
}

void FileUtils::convertToLower(string& word){
	transform(word.begin(), word.end(), word.begin(), ::tolower);
}

int FileUtils::getTotalWordCount()
{
	if(file.is_open())
	{
		file.seekg(0);
		int count = 0;
		string word;

		while(!file.eof()){               
			file >> word; 
			count++;
		}
		return count;
	}
	else
	{
		cout<<"\nError opening the file, cannot read this line!";
		return false;
	}
}

void FileUtils::removeNonAlphaNumChars(string &word)
{
	int index = 0;
	int len = word.length();
	while(index < len){
		if (!isalnum(word[index]) || word[index] == ' '){ 
			//removes one char at pos index
			word.erase(index,1);
			len--;
		}else
			index++;
	}
}
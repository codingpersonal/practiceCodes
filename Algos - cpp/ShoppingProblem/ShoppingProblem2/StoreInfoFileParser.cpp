#include"StoreInfoFileParser.h"
using namespace std;

StoreInfoFileParser::StoreInfoFileParser(string inFilePath):filePath(inFilePath) {
}

size_t StoreInfoFileParser::splitByChar(string input, char c, int pos)
{
	size_t found = input.find(c,pos);
	return found;
}

void StoreInfoFileParser::getStoreInfo(vector<storeData> &outVector)
{
	string currLine;
	FileUtils _fu(filePath);
	vector <string> fileFields;
	int index = 0;

	while(_fu.readNextLine(currLine)) 
	{
		fileFields.clear();
		//Split the line read by the file using '_'
		splitStoreData(currLine,fileFields);
		
		//populate a local store data object
		storeData s_obj;

		//Send this vector to fillStoreData which will split it further and fill up the storeData Structure object
		fillStoreData(fileFields,s_obj,index);

		//push back that local store data object in the outVectors
		outVector.push_back(s_obj);

		index++;
	}
}

void StoreInfoFileParser::fillStoreData(const vector<string> &fileFields, storeData &f_obj, int index)
{
		//Here now we initialise the number of objects of the struct
		std::vector<string>::const_iterator id;
		int found = 0;
		char buffer[50],buffer_1[50];
		int buf_size;

		int size = fileFields.size();

		//Copy the Store Id here
		f_obj.id = index;

		//Copy the Store Name here
		id = fileFields.begin();
		f_obj.storeName = (*id);
		id++;

		//Split the coordinates and copy them here
		found = splitByChar(*id,',',0);

		buf_size = (*id).copy(buffer,found,0);
		buffer[buf_size] = '\0';
		f_obj.xCoord = (atoi(buffer));

		buf_size = (*id).copy(buffer,(*id).size() - found,found + 1);
		buffer[buf_size] = '\0';
		f_obj.yCoord = atoi(buffer);

		id++;

		//Split the items here and copy them here
		for(int index = 0; index < size - 2; index++)
		{
			found = splitByChar(*id,':',0);

			buf_size = (*id).copy(buffer,found,0);
			buffer[buf_size] = '\0';

			buf_size = (*id).copy(buffer_1,(*id).size() - found,found + 1);
			buffer_1[buf_size] = '\0';
			f_obj.itemNamePriceMap[buffer] = atoi(buffer_1);

			id++;
		}
}

void StoreInfoFileParser::splitStoreData(string currLine,vector<string> &fileFields)
{
	//parse and split each line
	size_t found;
	int len = currLine.size();
	int pos = 0;
	char buffer[20];
	size_t buf_size;

	do
	{
		found = splitByChar(currLine,'_',pos);

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
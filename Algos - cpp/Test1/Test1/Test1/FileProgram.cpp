//This program reads from an input file line by line and then store the values in a strcuture.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct itemDetails
{
	string itemName;
	float price;
};

struct fileData
{
	string storeName;
	int xCoord;
	int yCoord;
	itemDetails *id;
};

class fileProblem
{
public:

	int numOfRecords;
	vector <fileData> f;
	string fileName;
	
	fileProblem()
	{
		numOfRecords = 0;
		fileName = "C:\\Users\\somya\\Downloads\\input.txt";
	}

	size_t splitByChar(string input, char c, int pos)
	{
		size_t found = input.find(c,pos);
		return found;
	}

	void fillFileRecord(vector <string> fileFields, int indx)
	{
		//Here now we initialise the number of objects of the struct
		fileData f_obj;
		std::vector<string>::const_iterator id;
		int found = 0;
		char buffer[50];
		int buf_size;

		int size = fileFields.size();

		cout<<"\nPrinting the records for store "<<indx+1;
		//Copy the Store Name here
		id = fileFields.begin();
		f_obj.storeName = (*id);
		id++;

		cout<<"\nStoreName is:"<<f_obj.storeName;

		//Split the coordinates and copy them here
		found = splitByChar(*id,',',0);

		buf_size = (*id).copy(buffer,found,0);
		buffer[buf_size] = '\0';
		f_obj.xCoord = (atoi(buffer));
		
		buf_size = (*id).copy(buffer,(*id).size() - found,found + 1);
		buffer[buf_size] = '\0';
		f_obj.yCoord = atoi(buffer);

		id++;
		
		cout<<"\nStore Location is:"<<f_obj.xCoord<<" "<<f_obj.yCoord;

		//Split the items here and copy them here
		f_obj.id = new itemDetails[size - 2];
		for(int index = 0; index < size - 2; index++)
		{
			found = splitByChar(*id,':',0);

			buf_size = (*id).copy(buffer,found,0);
			buffer[buf_size] = '\0';
			f_obj.id[index].itemName = buffer;
			
			buf_size = (*id).copy(buffer,(*id).size() - found,found + 1);
			buffer[buf_size] = '\0';
			f_obj.id[index].price = atoi(buffer);

			id++;

			cout<<"\nItem name and price is:"<<f_obj.id[index].itemName<<" "<<f_obj.id[index].price;
		}

		f.push_back(f_obj);
		cout<<"\n\n";
	}

	void splitFileRecord(string line, int recordNo)
	{
		cout<<"\n";
		size_t found;
		int len = line.size();
		int pos = 0;
		char buffer[20];
		size_t buf_size;
		vector <string> fileFields;
		fileFields.clear();

		do
		{
			found = splitByChar(line,'_',pos);

			if(found > len)
				break;
			else
			{			
				buf_size = line.copy(buffer,found - pos,pos);
				buffer[buf_size] = '\0';
				fileFields.push_back(buffer);
			}
			pos = found + 1;

		}while(found != string::npos);

		buf_size = line.copy(buffer,len - pos,pos);
		buffer[buf_size] = '\0';
		fileFields.push_back(buffer);

		fillFileRecord(fileFields, recordNo);
		
	}

	void readFromFile()
	{
		ifstream file(fileName);
		string line_file;
		
		if(file.is_open())
		{
			while(getline(file,line_file))
			{ 
				splitFileRecord(line_file,numOfRecords);				
				numOfRecords++;
				line_file.erase();
			}
			file.close();
		}
		else
			cout<<"\nError opening the file!";
	}
};

int main_file1()
{
	fileProblem obj;

	obj.readFromFile();
	
	return 0;
}
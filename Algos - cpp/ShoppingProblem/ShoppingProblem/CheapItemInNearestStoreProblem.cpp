//This program reads from an input file line by line and then store the values in a strcuture.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include "shortDistance.h"
#include "CheapItemInNearestStoreProblem.h"

using namespace std;



class fileProblem
{
public:

	int numOfRecords;
	int numOfItems;
	int *seq;

	vector <storeData> storeData_obj;	
	shortestDis s_obj;

	string userFileName;		//why do u need to store these paths?
	string storeFileName;

	std::map<string,int> itemNameLowestPrice;
	std::map<string,string> itemNameStoreName;
	std::map<string,coord> storeNameCoordinate;
	std::map<int,string> storeNameId;		//why again member?

	set<string> cheapestStore;

	fileProblem()
	{
		numOfRecords = 0;
		numOfItems = 0;

		storeFileName = "C:\\Users\\somya\\Downloads\\input.txt";
		userFileName = "C:\\Users\\somya\\Downloads\\ip.txt";
	}

	//This function takes a string and splits it from the mentioned position by the character passed.
	size_t splitByChar(string input, char c, int pos)
	{
		size_t found = input.find(c,pos);
		return found;
	}

	void fillFileRecord(vector <string> fileFields, int indx)
	{
		//Here now we initialise the number of objects of the struct
		storeData f_obj;
		std::vector<string>::const_iterator id;
		int found = 0;
		char buffer[50],buffer_1[50];
		int buf_size;

		int size = fileFields.size();

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

		storeData_obj.push_back(f_obj);
		//cout<<"\n\n";
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
		ifstream file(storeFileName);
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

	//This function populates the Map where store name is mapped to an ID.
	//It also popluates the seq variable which is then needed to generate the permuations of all the sequences.
	void populateStoreNameIdMap()
	{
		int noOfStores = storeNameCoordinate.size();
		int id = 1;
		seq = new int[noOfStores];
		std::set<string>::iterator it = cheapestStore.begin();

		for(int index = 0; index < noOfStores; index++)
		{
			storeNameId[id] = (*it);
			seq[index] = id;
			id++;
			it++;
		}
	}

	//This function fills the array of structure objects by the coordinates of the cheapest store.
	//These values are then used by the header file to calculate the shortest distance.
	void fillCoordinateStruct()
	{
		int size = storeNameCoordinate.size();
		string name;
		coord temp_obj;

		for(int index = 0; index < size; index++)
		{
			name = storeNameId[index + 1];
			temp_obj = storeNameCoordinate[name];

			s_obj.c[index].xc = temp_obj.xc;
			s_obj.c[index].yc = temp_obj.yc;
		}
	}

	void findCheapestStore(string item, int *totPrice)
	{
		int min_price = 9999;
		int price;
		
		string cheapStore;
		coord c_obj;
		

		for(int i=0; i < storeData_obj.size(); i++) 
		{
			storeData &currStore = storeData_obj[i];
			//check if item is present
			if(currStore.itemNamePriceMap.count(item) > 0) 
			{
				price = currStore.itemNamePriceMap[item];
				if(price < min_price)
				{
					min_price = price;
					cheapStore = currStore.storeName;
					c_obj.xc = currStore.xCoord;
					c_obj.yc = currStore.yCoord;
				}
			}
		}

		itemNameLowestPrice[item] = min_price;
		itemNameStoreName[item] = cheapStore;
		cheapestStore.insert(cheapStore);

		storeNameCoordinate[cheapStore] = c_obj;
		
		*totPrice += min_price;

	}

	void readUserInputFile(int *totPrice)
	{
		ifstream file(userFileName);
		string line_file;
		
		if(file.is_open())
		{
			getline(file,line_file);
			while(!file.badbit)
			{ 
				findCheapestStore(line_file,totPrice);
				numOfItems++;
				line_file.erase();
				getline(file,line_file);
			}
			file.close();
		}
		else
			cout<<"\nError opening the file!";
	}

	void printDisNRoute()
	{
		int index;
		int id;

		cout<<"\nThe shortest distance is: "<<s_obj.min_dis;
		cout<<"\n\nThe shortest route is:"<<"Home";
		for(index = 0; index < s_obj.numOfCities; index++)
		{
			id = s_obj.min_route[index];
			cout<<"->"<<storeNameId[id];
		}
		cout<<"->Home\n\n";
	}

	void getRoute()
	{
		int totPrice = 0;
		readFromFile();
		readUserInputFile(&totPrice);

		populateStoreNameIdMap();
		fillCoordinateStruct();
		int noOfStores = storeNameCoordinate.size();

		s_obj.numOfCities = noOfStores;		

		s_obj.generateSeq(seq,0,noOfStores);
		s_obj.checkSeqAndFindShortest();
	
		cout<<"\n\n\n";
		printDisNRoute();

		cout<<"\nTotal user bill is:"<<totPrice;

	}

	~fileProblem()
	{
		delete [] seq;
		cout<<"\nDestructor cleaned up from class in cpp file!";
	}
	
};

int main()
{
	fileProblem obj;
	obj.getRoute();

	return 0;
}

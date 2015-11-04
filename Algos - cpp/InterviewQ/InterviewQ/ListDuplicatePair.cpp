/*Given set of job schedules with start and end time, write a function that returns indexes of overlapping sets. 

for ex :- 
input -> [1,2][5,6][1,5][7,8][1,6] 
return -> [0,1,2,4]

*/
#include<iostream>
#include <set>
#include <utility>
#include <map>
#include<vector>

using namespace std;

class jobSch
{
public:
	jobSch();

	//this poplulates the map where in all the input info is stored.
	//This also populates the vector for reverse mapping
	void populateJobSchMap(int startTime, int endTime,int index);
	
	//prints the output set which has the required indexes
	void printOutputIndex();

	//finds the jobs which are overlapping
	void findOverlappingJobs();

	~jobSch();

private:
	//stores map of the pair of job to indexing
	std::map< std::pair<int,int>,int >jobTime;

	//stores the set of the output index
	std::vector<std::set<int>> outSet;

	//stores the reverse mapping of the jobs to the index of the vector.
	std::vector<std::pair<int,int>>indexToJob;
};

jobSch::jobSch(){
}

jobSch::~jobSch(){
}

void jobSch::populateJobSchMap(int startTime, int endTime, int index){
	std::pair<int,int>time;

	time.first = startTime;
	time.second = endTime;
	
	jobTime[time] = index;
	indexToJob.push_back(time);
}

void jobSch::printOutputIndex(){
	int min, max;
	for(int index = 0; index < outSet.size(); index++){
		cout<<"[";
		set<int>output = outSet[index];
		set<int>::const_iterator s_it = output.begin();
		min = indexToJob[*s_it].first;
		max = indexToJob[*s_it].second;
		while(s_it != output.end()){
			cout<<*s_it<<" ";
			if(min > indexToJob[*s_it].first)
				min = indexToJob[*s_it].first;
			if(max < indexToJob[*s_it].second)
				max = indexToJob[*s_it].second;
			s_it++;
		}
		cout<<"] Min:"<<min<<" ,Max:"<<max<<"\n\n";

	}
	
}

void jobSch::findOverlappingJobs()
{
	map<pair<int,int>,int>::iterator it = jobTime.begin();
	std::set<int> out_index;
	int maxEndTime = (it->first).second;

	//check for the current pair and the next one in the map list.
	while(it != jobTime.end())
	{
		pair<int,int> curr_p = it->first;
		int currId = it->second;

		it++;
		pair<int,int> next_p;
		int nextId = -1;

		if (it != jobTime.end()) {
			next_p = (it)->first;
			nextId = it->second;
		}

		if(nextId != -1 && 
			(curr_p.first == next_p.first || maxEndTime > next_p.first)
		)
		{
			out_index.insert(currId);
			out_index.insert(nextId);

			if(maxEndTime < next_p.second)
				maxEndTime = next_p.second;
		}
		else{
			//one set is complete, push that in vector now
			outSet.push_back(out_index);

			//clear the set to accomodate new values now
			out_index.clear();

			//update the maxEndTime variable
			maxEndTime = next_p.second;
		}
	}
}

int main()
{
	int startTime, endTime;
	char ch;
	jobSch obj;

	obj.populateJobSchMap(1, 2, 0);
	obj.populateJobSchMap(1, 3, 1);
	obj.populateJobSchMap(1, 6, 2);
	obj.populateJobSchMap(7, 8, 3);
	obj.populateJobSchMap(7, 9, 4);
	obj.populateJobSchMap(10, 14, 5);
	obj.populateJobSchMap(8, 9, 6);
	obj.populateJobSchMap(2, 5, 7);
	obj.populateJobSchMap(13, 15, 8);
	obj.populateJobSchMap(3, 4, 9);

	//int count = 0;
	//cout<<"\nHow many jobs do you want to schedule?";
	//cin>>count;

	//for(int index = 0; index < count; index++){
	//	cout<<"\nEnter the job schedules(start time and end time)";
	//	cin>>startTime>>endTime;

	//	obj.populateJobSchMap(startTime, endTime, index);
	//}
	
	obj.findOverlappingJobs();
	obj.printOutputIndex();
	return 0;
}
using namespace std;

#include<iostream>
#include<math.h>
#include<vector>

struct coordinates
	{
		int x;
		int y;
	};

class shortestDis
{
	public:

	int min_dis;
	int *min_route;
	int numOfCities;
	std::vector <int*> seq_v;
	coordinates *c;
	
	shortestDis()
	{
		min_dis = 9999;
		numOfCities = 10;
		c = new coordinates[numOfCities];
		int *min_route = new int[numOfCities];
		for(int index = 0; index < numOfCities; index++)
			min_route[index] = 0;
	}

	double getDistanceFromCoordinates(int Sx,int Sy, int Dx, int Dy)
	{
		double term1 = abs(Sy - Dy);
		double term2 = abs(Sx - Dx);

		double distance = pow(term1 , 2) + pow (term2, 2);
		distance = sqrt(distance);

		return distance;
		
	}

	int calculateDistance(int *seq)
	{
		/*cout<<"\nIncoming sequence is:";
		for(int i=0;i<5;i++)
			cout<<seq[i];*/

		int sum = 0;
		int index = 0;

		sum = sum + getDistanceFromCoordinates(0,0,c[seq[0] - 1].x,c[seq[0] - 1].y);

		for(index = 0; index < numOfCities - 1; index++)
		{
			sum = sum + getDistanceFromCoordinates(c[seq[index] - 1].x,c[seq[index] - 1].y,c[seq[index + 1] - 1].x,c[seq[index + 1] - 1].y);
		}

		sum = sum + getDistanceFromCoordinates(0,0,c[seq[index] - 1].x,c[seq[index] - 1].y);

		return sum;
	}

	void generateSeq(int *seq,int startIndex, int count)		
	{
		

		int index = 0;
		int rot_count = 0;

		//terminating condition
		if(startIndex + 1 == count)
		{
			int *temp_ptr = new int[numOfCities];
			for(index = 0; index <numOfCities; index++)
				temp_ptr[index] = seq[index];
			seq_v.push_back(temp_ptr);
		}

		for(int i=startIndex; i < count; i++) 
		{
			//swap ith element with the startIndex element
			int temp = seq[i];
			seq[i] = seq[startIndex];
			seq[startIndex] = temp;

			generateSeq(seq,startIndex+1, count);

			temp = seq[i];
			seq[i] = seq[startIndex];
			seq[startIndex] = temp;

		}
	}

	void printDisNRoute()
	{
		int index;
		cout<<"\nThe shortest distance is: "<<min_dis;
		cout<<"\n\nThe shortest route is:"<<"Home";
		for(index = 0; index < numOfCities; index++)
		{
			cout<<"->"<<min_route[index];
		}
		cout<<"->Home\n\n";
	}

	void checkSeqAndFindShortest()
	{
		int count = 0;

		std::vector<int *>::const_iterator id;
		for(id = seq_v.begin(); id != seq_v.end() ; ++id)
		{
			count = calculateDistance(*id);

			if(count < min_dis)
			{
				min_dis = count;
				//int *temp_ptr = new int[numOfCities];

				//for(int i=0; i<numOfCities; i++)
				//{
				//	temp_ptr[i] = (*id)[i];
				//}

				min_route = (*id);
			}
		}
	}

	void printVector()
	{
		std::vector<int *>::const_iterator id;
		for(id = seq_v.begin(); id != seq_v.end() ; ++id)
		{
			cout<<"\n";
			for(int i=0;i<numOfCities;i++)
				cout<<(*id)[i];
		}
	}

	~shortestDis()
	{
		std::vector<int *>::const_iterator id;
		for(id = seq_v.begin(); id != seq_v.end() ; ++id)
		{
			delete [] (*id);
		}
		delete [] c;
		cout<<"\nDestructor cleaned up!\n";
	}
};

int main_sd()
{
	int index;
	shortestDis *s = new shortestDis;

	//debug code
	for(index = 0; index < s->numOfCities; index++) {
		s->c[index].x = index+1;
		s->c[index].y = index+1;
	}
	
	//cout<<"\nEnter the coordinates for the 5 cities(x,y):";
	//for(index = 0; index < s.numOfCities; index++)
	//{
	//	cout<<"\nCity "<<index + 1<<":";
	//	cin>>s.c[index].x>>s.c[index].y;
	//}
	//
	int * seq_loc = new int[s->numOfCities];
	for(index = 0; index < s->numOfCities; index++)
	{
		seq_loc[index] = index + 1;
	}

	s->generateSeq(seq_loc,0,s->numOfCities);
	s->checkSeqAndFindShortest();
	
	cout<<"\n\n\n";
	s->printDisNRoute();

	delete [] seq_loc;
	delete s;

	return 0;
}
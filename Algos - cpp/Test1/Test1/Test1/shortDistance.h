using namespace std;

#include<iostream>
#include<math.h>
#include<vector>

struct coord
{
	int xc;
	int yc;
};

class shortestDis
{
	public:

	int min_dis;
	int *min_route;
	int numOfCities;
	std::vector <int*> seq_v;
	coord *c;
	
	shortestDis()
	{
		min_dis = 9999;
		numOfCities = 10;
		c = new coord[numOfCities];
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
		int sum = 0;
		int index = 0;

		sum = sum + getDistanceFromCoordinates(0,0,c[seq[0] - 1].xc,c[seq[0] - 1].yc);

		for(index = 0; index < numOfCities - 1; index++)
		{
			sum = sum + getDistanceFromCoordinates(c[seq[index] - 1].xc,c[seq[index] - 1].yc,c[seq[index + 1] - 1].xc,c[seq[index + 1] - 1].yc);
		}

		sum = sum + getDistanceFromCoordinates(0,0,c[seq[index] - 1].xc,c[seq[index] - 1].yc);

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
		cout<<"\nDestructor cleaned up from class in header file!\n";
	}
};


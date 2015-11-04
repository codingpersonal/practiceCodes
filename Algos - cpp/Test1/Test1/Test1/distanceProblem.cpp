using namespace std;
#include<iostream>
#include<math.h>

class shortestDis
{
	public:

	int min_dis;
	int *min_route;


	struct coordinates
	{
		int x;
		int y;
	}c[5];

	shortestDis()
	{
		min_dis = 9999;
		int *min_route = new int[5];
		for(int index = 0; index < 5; index++)
			min_route[index] = 0;
	}
	double getDistance(int Sx,int Sy, int Dx, int Dy)
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

		sum = sum + getDistance(0,0,c[seq[0] - 1].x,c[seq[0] - 1].y);

		for(index = 0; index < 4; index++)
		{
			sum = sum + getDistance(c[seq[index] - 1].x,c[seq[index] - 1].y,c[seq[index + 1] - 1].x,c[seq[index + 1] - 1].y);
		}

		sum = sum + getDistance(0,0,c[seq[index] - 1].x,c[seq[index] - 1].y);

		return sum;
	}

	void generateSeq(int *seq,int startIndex, int count)		
	{
		

		int index = 0;
		int rot_count = 0;

		//terminating condition
		if(startIndex + 1 == count)
		{
			int distance = calculateDistance(seq);
			if(distance < min_dis)
			{
				int *temp_ptr = new int[5];
				min_dis = distance;
				for(index = 0; index < 5; index++)
				{
					temp_ptr[index] = seq[index];
				}

				min_route = temp_ptr;
			}
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
		for(index = 0; index < 5; index++)
		{
			cout<<"->"<<min_route[index];
		}
		cout<<"->Home\n\n";
	}
};

int main_distanceProblem()
{
	int index;
	shortestDis s;
	
	cout<<"\nEnter the coordinates for the 5 cities(x,y):";
	for(index = 0; index < 5; index++)
	{
		cout<<"\nCity "<<index + 1<<":";
		cin>>s.c[index].x>>s.c[index].y;
	}
	
	int * seq_loc = new int[5];
	for(index = 0; index < 5; index++)
	{
		seq_loc[index] = index + 1;
	}

	s.generateSeq(seq_loc,0,5);
	
	cout<<"\n\n\n";
	s.printDisNRoute();

	return 0;
}
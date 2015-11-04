#include"ShortestDistance.h"

ShortestDistance::ShortestDistance(int citiesCount, map<int, coord> &coor): numOfCities(citiesCount), c(coor)
{
	min_dis = INFINITY;
	int *min_route = new int[numOfCities];
	for(int index = 0; index < numOfCities; index++)
		min_route[index] = 0;
}

double ShortestDistance::getDistanceFromCoordinates(int Sx,int Sy, int Dx, int Dy)
{
	double term1 = abs(Sy - Dy);
	double term2 = abs(Sx - Dx);

	double distance = pow(term1 , 2) + pow (term2, 2);
	distance = sqrt(distance);

	return distance;

}

int ShortestDistance::calculateDistance(int *seq)
{
	int sum = 0;
	int index = 0;

	sum = sum + getDistanceFromCoordinates(0,0,c[seq[0]].xc,c[seq[0]].yc);

	for(index = 0; index < numOfCities - 1; index++)
	{
		sum = sum + getDistanceFromCoordinates(c[seq[index]].xc,c[seq[index]].yc,c[seq[index + 1]].xc,c[seq[index + 1] ].yc);
	}

	sum = sum + getDistanceFromCoordinates(0,0,c[seq[index]].xc,c[seq[index]].yc);

	return sum;
}

void ShortestDistance::generateSeq(int *seq,int startIndex, int count)		
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

void ShortestDistance::checkSeqAndFindShortest()
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

void ShortestDistance::printVector()
{
	std::vector<int *>::const_iterator id;
	for(id = seq_v.begin(); id != seq_v.end() ; ++id)
	{
		cout<<"\n";
		for(int i=0;i<numOfCities;i++)
			cout<<(*id)[i];
	}
}

void ShortestDistance::printShortestDistance() {

	cout<<"\nmin dist is "<<min_dis;
	cout<<"\nshortest dist is \t";
	for(int i=0; i < numOfCities; i++) {
		cout<<min_route[i]<<" -> ";
	}
}


ShortestDistance::~ShortestDistance()
{
	std::vector<int *>::const_iterator id;
	for(id = seq_v.begin(); id != seq_v.end() ; ++id)
	{
		delete [] (*id);
	}
	cout<<"\nDestructor cleaned up from class in header file!\n";
}

#ifndef shortDistance_H
#define shortDistance_H

#define INFINITY 99999
using namespace std;
#include<string>
#include<iostream>
#include<math.h>
#include<vector>
#include <map>

struct coord
{
	int xc;
	int yc;
};

using namespace std;

class ShortestDistance
{
	public:
	
	int min_dis;
	int *min_route;
	int numOfCities;
	std::vector <int*> seq_v;
	map<int, coord>  c;
	
	ShortestDistance(int citiesCount, map<int, coord> &coor);
	double getDistanceFromCoordinates(int,int,int,int);
	int calculateDistance(int *);
	void generateSeq(int *,int,int);

	void checkSeqAndFindShortest();
	void printVector();
	void printShortestDistance();
	~ShortestDistance();
};

#endif
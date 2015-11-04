#ifndef shortDistance_H
#define shortDistance_H

#define INFINITY 99999
using namespace std;
#include<string>
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
	
	shortestDis(int citiesCount);
	double getDistanceFromCoordinates(int,int,int,int);
	int calculateDistance(int *);
	void generateSeq(int *,int,int);
	void checkSeqAndFindShortest();
	void printVector();
	~shortestDis();
};

#endif
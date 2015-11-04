using namespace std;

#include<iostream>

void toh(int disk, int beg, int end, int aux)
{
	if(disk == 0)
		return;
	else
	{
		//move n-1 disks from a->c using b as auxillary
		toh(disk - 1,1,3,2);

		cout<<"Move disk:"<<disk<<" from 1 to 2";

		//move the n-1 disks from c->b using a as aux
		toh(disk-1, 3,2,1);
	}
}


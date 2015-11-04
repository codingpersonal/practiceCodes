using namespace std;
#include <iostream>

/*

Given two digital clock digits, return (how many lights turn on) + (how
many lights turn off) when switching from the first digit to the second.


	 ---         5
	|   |      1   2
	 ---         6
	|   |      3   4
	 ---         7

*/

bool isBitSetOnPos(unsigned char c, int pos)
{
	char check[7] = {1,2,4,8,16,32,64};
	if((c & check[pos]) > 0)
		return 1;
	else
		return 0;
}

int getSegmentCount (int n1, int n2)
{
	int count = 0;
	int index = 0;

	unsigned char segment[10] = {  95  /*0b01011111 0*/, 
						  10  /*0b00001010 1*/, 
						  118 /*0b01110110 2*/, 
						  122 /*0b01111010 3*/,
						  43  /*0b00101011 4*/, 
						  121 /*0b01111001 5*/,
						  125 /*0b01111101 6*/, 
						  26  /*0b00011010 7*/, 
						  127 /*0b01111111 8*/, 
						  123 /*0b01111011 9*/};

	unsigned char res = segment[n1] ^ segment[n2];

	for(index = 0; index < 7; index++)
	{
		if(isBitSetOnPos(res,index))
			count++;
	}
	return count;
}

//int getSegmentCount (int n1, int n2)
//{
//	int count = 0;
//	int index = 0;
//	char segment[10] = {  95  /*0b01011111 0*/, 
//						  10  /*0b00001010 1*/, 
//						  118 /*0b01110110 2*/, 
//						  122 /*0b01111010 3*/,
//						  43  /*0b00101011 4*/, 
//						  121 /*0b01111001 5*/,
//						  125 /*0b01111101 6*/, 
//						  26  /*0b00011010 7*/, 
//						  127 /*0b01111111 8*/, 
//						  123 /*0b01111011 9*/};
//
//	for(index = 0; index < 7; index++)
//	{
//		if(isBitSetOnPos(segment[n1] , index) ^ isBitSetOnPos(segment[n2], index))
//		{
//			count++;
//		}
//	}
//	return count;
//}

int main_1()
{
	int n1, n2;
	int count = 0;

	cout<<"\nEnter two numbers(0-9):";
	cin>>n1>>n2;
	count = getSegmentCount(n1, n2);

	cout<<"\nNumber of segments needed to be changed are:"<<count;

	return 0;
}

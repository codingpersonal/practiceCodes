using namespace std;
#include<iostream>

/*Inputs an array of size count and changes it by one circular rotation
eg: [123] = [312]*/
void rotateArray(int *pptr, int count)
{
	int temp = pptr[count - 1];
	for(int index = count - 1; index >= 1; index--)
	{
		pptr[index] = pptr[index - 1];
	}
	
	pptr[0] = temp;
}

void printSeq(int *seq, int count)
{
	cout<<"\n";
	for(int index = 0; index < count; index++)
	{
		cout<<seq[index]<<" ";
	}
}

//it generates all permutations of the seq starting from startIndex uptil count. chars before startIndex (if startIndex > 0) are assumed to be fixed. 
// when one ptn is complete, it will print the whole array.
// count is total count

void generateSeq(int *seq,int startIndex, int count)		
{
	int index = 0;
	int rot_count = 0;

	//terminating condition
	if(startIndex + 1 == count)
	{
		printSeq(seq, count);
	}

	for(int i=startIndex; i < count; i++) {
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

int main_seq()
{
	int elemCount = 3;
	int *ptr_array = new int[elemCount];
	for(int i=0; i < elemCount; i++) 
		ptr_array[i] = i+1;

	generateSeq(ptr_array, 0, elemCount);
	return 0;
}
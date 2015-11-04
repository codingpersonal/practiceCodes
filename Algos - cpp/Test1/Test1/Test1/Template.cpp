#include <iostream>

using namespace std;

template <typename T>
void print (T *ptr, int len) 
{ 
    for(int index = 0; index < len; index++)
	{
		cout<<ptr[index]<<" ";
	}
} 
int main_template ()
{
 
    char *ptr = new char[10];
	cout<<"\nEnter a character string to print:";
	cin>>ptr;
	cout<<"\nThe character array is:";
	print(ptr, strlen(ptr));

	int *arr = new int[10];
	for(int index = 0; index < 10; index++)
	{
		arr[index] = index + 1;
	}
	cout<<"\nThe integer array is:";
	print(arr,10);

	return 0;
}

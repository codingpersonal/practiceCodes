using namespace std;
#include<iostream>

void printStr(char *str)
{
	int len = strlen(str);
	cout<<"\nOutput String is:";
	for(int index = 0; index < len; index++)
	{
		cout<<str[index];
	}
	cout<<"\n";
}

void printInt(int *str, int range)
{
	cout<<"\nOutput is:";
	for(int index = 0; index < range; index++)
	{
		cout<<str[index]<<" ";
	}
	cout<<"\n";
}

void reverse(char *str, int startIndex, int lastIndex, int len)
{
	char temp;

	//Terminating condition
	if(lastIndex <= startIndex)
	{
		printStr(str);
	}
	else
	{
		temp = str[startIndex];
		str[startIndex] = str[lastIndex];
		str[lastIndex] = temp;

		reverse(str, startIndex + 1, lastIndex - 1, len);
	}
}

void rev_opt(char *str, int len)
{	
	if(len <= 1)
	{
		return;
	}
	else
	{
		char temp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = temp;
	
		str++;
		len = len - 2;

		rev_opt(str, len);
	}
}

int factorial(int num)
{
	if(num == 0)
		return 1;
	else
		return num * factorial(num - 1);
}

void fibo(int *ptr,int index, int range)
{
	if(index == range)
	{
		printInt(ptr, range);
	}
	else
	{
		ptr[index] = ptr[index - 1] + ptr[index - 2];
		fibo(ptr, index + 1, range);
	}
}

void reverseMainCode()
{
	char *ptr = new char[10];
	cout<<"\nEnter a string upto 10 characters:";
	cin>>ptr;

	int len = strlen(ptr);
	cout<<"\nString length is:"<<len<<"\n";

	int startIndex = 0;
	int lastIndex = len - 1;

	reverse(ptr,startIndex, lastIndex, len);
}

void FactorialMainCode()
{
	int num;
	cout<<"\nEnter a number:";
	cin>>num;

	int res = factorial(num);
	cout<<"\nFactorial of the number is:"<<res<<"\n";
}

void fiboMainCode()
{
	
	int range;
	cout<<"Enter a range for Fibonacci:";
	cin>>range;

	int *ptr = new int[range];

	if(range == 1)
	{
		ptr[0] = 0;
		printInt(ptr, range);
	}
	else if(range == 2)
	{
		ptr[0] = 0;
		ptr[1] = 1;
		printInt(ptr, range);
	}
	else
	{
		ptr[0] = 0;
		ptr[1] = 1;
		int index = 2;

		fibo(ptr, index, range);
	}
}

int getTermFibo(int n)
{
	if(n == 1)
		return 1;
	else if(n == 0)
		return 0;
	else
		return (getTermFibo(n - 1) + getTermFibo(n - 2));
}

//Problem statement: you are on a certain staircase step and wants to come down to step-1 which is the ground level.
//Can come either one step down or two steps down at a time.
//This program returns the number of ways in which you can come down.
int getNumOfWays(int step)
{
	if(step < 1)
	{
		return 0;
	}
	else if(step == 1)
		return 1;
	else
	{
		return getNumOfWays(step - 2) +	getNumOfWays(step - 1);
	}
}

//Tower of Hanoi Problem
void toh(int disk, int beg, int end, int aux)
{
	if(disk == 1)
	{
		cout<<"\nMove top disk from "<<beg<<" to "<<end;
		return;
	}

	//move n-1 disks from a->c using b as auxillary
	toh(disk - 1, beg , aux , end);

	cout<<"\nMove top disk from "<<beg<<" to "<<end;

	//move the n-1 disks from c->b using a as aux
	toh(disk-1, aux , end ,beg);
}

void TOHmain()
{
	int disk;
	cout<<"\nEnter the number of disks you want to start with:";
	cin>>disk;

	//work for disks where move from rod 1 to rod 2 using rod 3 as aux
	toh(disk,1,2,3);
}

void main_rec()
{
	TOHmain();
}
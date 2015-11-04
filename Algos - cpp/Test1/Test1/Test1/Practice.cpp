using namespace std;
#include<iostream>

void temp_fun(int &a, int &b) {
	
	cout<<"Value of a is:"<<a;
	cout<<"\nValue of b is:"<<b;
	cout<<"\nAddress of a is:"<<&a;
	cout<<"\nAddress of b is:"<<&b;

}

void main() {
	int *a = new int;
	int b = 20;
	*a = 10;

	temp_fun(*a,b);
	
}


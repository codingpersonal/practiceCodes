using namespace std;

#include<iostream>
#include<string>

int main_str()
{
	string s1("This is a sample string\n");
	cout<<s1;

	cout<<"\nSize of the string is:"<<s1.size();

	s1.clear();
	cout<<"\nString after using clear is:"<<s1; //Size becomes 0 now
	cout<<s1.size();

	s1 = "somya";
	cout<<"\nNew string is:"<<s1;

	cout<<"\n";
	return 0;
}
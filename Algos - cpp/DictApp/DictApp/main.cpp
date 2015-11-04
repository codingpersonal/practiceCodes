using namespace std;

#include<iostream>
#include<string>

int main(){
	int choice;
	string word;

	cout<<"Welcome to Dictionary App\n";
	cout<<"1. Enter a word to search for it's meaning\n";
	cout<<"2. Load random word of the day with it's meaning\n";
	cout<<"3. Take a Quiz!\n";

	cout<<"Enter your choice:\n";
	cin>>choice;

	switch (choice){
	case 1:
		cin>>word;

		break;

	case 2:
		break;

	case 3:
		break;

	default: 
		cout<<"\nInvalid Input";
	}

	return 0;
}
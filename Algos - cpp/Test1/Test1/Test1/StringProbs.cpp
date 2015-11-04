using namespace std;
#include<iostream>

int countUsingStrPointer = 0;

#define FOR(n,m)		for(int i=n; i <m; i++)

class stringHelper
{
	char *str;

	void resetLetters(int arr[], int val, int size)
	{
		FOR(0,size)
			arr[i] = val;
	}

	public:
	stringHelper(char *input)
	{
		str = input;
		countUsingStrPointer++;
	}

	void getMaxNonRepSubstring()
	{
		int letter[26];
		int startIndex = 0;
		int len = strlen(str);
		int val;
		int count= 0, maxCount = 0;
		int fromIndex, toIndex;

		resetLetters(letter, -1, 26);

		FOR(startIndex,len)
		{
			//Taking the ASCII code of the character which is coming, considering the string is in lowercase;
			val = str[i];
			
			if(letter[val - 97] == -1)
			{
				//Now setting the offset into 26 size letter array, say ascii of a=97, so setting it at letter[0]
				letter[val - 97] = i;
				count++;
			}
			else //That letter now got repeated
			{
				//If two substrings are of equal length found, it will consider the first one
				if(maxCount < count)
				{
					maxCount = count;
					fromIndex = startIndex;
					toIndex = i - 1;
				}

				//Start the loop from the next position of the repeating letter.
				//Say string is Saurabh, after you reach Saura, then terminate here and start the next loop from 'u' now
				//So it should be last pos + 1, but i will increment itself in for loop, so dont increment here
				i = letter[val - 97];
				startIndex = i + 1;

				//Reset the letters again now
				resetLetters(letter, -1, 26);

				//Reset the count too
				count = 0;
			}
		}

		if(count > maxCount)
		{
			maxCount = count;
			fromIndex = startIndex;
			toIndex = len;
		}

		cout<<"\nThe maximum length is: "<<maxCount<<" and the substring is : ";
		FOR(fromIndex,toIndex+1)
			cout<<str[i]<<" ";
	}
	~stringHelper()
	{
		countUsingStrPointer--;
		if(countUsingStrPointer == 0)
		{
			free(str);
		}
	}
};

int main_string()
{
	char *ptr = new char[20];
	cout<<"\nEnter a string:";
	cin>>ptr;

	stringHelper strObj(ptr);
	strObj.getMaxNonRepSubstring();

	cout<<"\n";
	return 0;
}

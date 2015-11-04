using namespace std;

#include<iostream>

/*
1. Array define on stack memory and print (integer, character, float)
2. Array input from stdin and then store and then print
2.5 Two dimensional array define on stack memory
3. Dynamic length of input integer array
4. Dynamic length of input character array
5. take two dynamic length strings as input and then concat it. 
*/

/*
6. pointer to pointer declare and work on it
7. find number of elements in an array
8. find length of a string (stored in a character array) w and w/o using strlen
9. add two strings w and w/o using strcat
10. Take a string from user of unknown length till the user enters new line character
*/

/*
11. Iterate a 1D array using a pointer
12. Implementation of struct using pointers
13. Iterate a 1D array using array of pointers
14. Iterate a 2D array using array of pointers
15. Implementation of a LL
*/

/*
16. Pointers and strings sample programs
*/

/*
1. http://www.cquestions.com/2010/06/array-questions-with-explanation-in-c.html
2. Why return o from int main() and who consumes this returned value
*/

void q1() 
{
	int int_arr[10] = {1,2,3,4,5,6,7,8,9,10};
	char c_arr[10] = {'s','o','m','y','a','s','a','u','r','abh'}; // Here if you store 3 charcters instead of one, then the last one will get replaced.
	float f_arr[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
	int index = 0;

	cout<<"\nInteger Array is as:";
	for(index = 0; index < 10; index++)
	{
		cout<<int_arr[index]<<" ";
	}

	cout<<"\Character Array is as:";
	for(index = 0; index < 10; index++)
	{
		cout<<c_arr[index];
	}

	cout<<"\nFloat Array is as:";
	for(index = 0; index < 10; index++)
	{
		cout<<f_arr[index]<<" ";
	}

	cout<<"\n";
}

void q2() 
{
	int int_arr[10];
	char c_arr[10];
	float f_arr[10];
	int index = 0;

	cout<<"Enter 10 elements of interger type";
	for(index = 0; index < 10; index++)
	{
		cin>>int_arr[index];
	}

	cout<<"\nEnter 10 elements of character type";
	for(index = 0; index < 10; index++)
	{
		cin>>c_arr[index];
	}

	cout<<"\nEnter 10 elements of float type";
	for(index = 0; index < 10; index++)
	{
		cin>>f_arr[index];
	}

	cout<<"\nInteger Array is as:";
	for(index = 0; index < 10; index++)
	{
		cout<<int_arr[index]<<" ";
	}

	cout<<"\Character Array is as:";
	for(index = 0; index < 10; index++)
	{
		cout<<c_arr[index]<<" ";
	}

	cout<<"\nFloat Array is as:";
	for(index = 0; index < 10; index++)
	{
		cout<<f_arr[index]<<" ";
	}

	cout<<"\n";

}

void q2_5() 
{
	int int_arr[3][3] = { {1,2,3},
	{4,5,6},
	{7,8,9} } ;
	
	int row = 0, col = 0;

	cout<<"\nInteger Array is as:\n";
	for(row = 0; row < 3; row++)
	{
		for(col = 0; col < 3; col ++)
		{
			cout<<int_arr[row][col]<<" ";
		}

		cout <<"\n";
	}
cout<<"\n";

}

void q3()
{ 
	int size = 0, index = 0;
	cout<<"\nEnter the size of array you want to enter:";
	cin>>size;

	int *arr = new int(size);

	cout<<"\nEnter the elements now:";
	for(index = 0; index < size; index++)
	{
		cin>>arr[index];
	}

	cout<<"\nThe elements of the array are:";
	for(index = 0; index < size; index++)
	{
		cout<<arr[index]<<" ";
	}

	for(index = 0; index < size; index++)
	{
		cout<<*arr<<" ";
		arr++;
	}
	
}

//need to initiaze the last element explicitly
void q4()
{ 
	int size = 0, index = 0;
	cout<<"\nEnter the size of array you want to enter:";
	cin>>size;

	char *arr = new char(size + 1);

	cout<<"\nEnter the elements now:";
	for(index = 0; index < size; index++)
	{
		cin>>arr[index];
	}

	arr[size] = '\0';

	cout<<"\nThe elements of the array are:";
	for(index = 0; index < size; index++)
	{
		cout<<arr[index]<<" ";
	}

	cout<<"\n\n";

	index = 0;
	while(arr[index] !='\0')
	{
		cout<<arr[index++]<<" ";
	}
}

void q5()
{ 
	int size1 = 0, size2 = 0, index = 0;

	cout<<"\nEnter the size of string_1 you want to enter:";
	cin>>size1;

	cout<<"\nEnter the size of string_2 you want to enter:";
	cin>>size2;

	char *arr1 = new char(size1 + 1);
	char *arr2 = new char(size2 + 1);
	char *arr3 = new char(size1 + size2 + 1);

	//Input String1
	cout<<"\nEnter string1:";
	for(index = 0; index < size1; index++)
	{
		cin>>arr1[index];
	}
	arr1[size1] = '\0';

	//Input String2
	cout<<"\nEnter string2:";
	for(index = 0; index < size2; index++)
	{
		cin>>arr2[index];
	}
	arr2[size2] = '\0';

	//Output String
	cout<<"\nString1 is:";
	for(index = 0; index < size1; index++)
	{
		cout<<arr1[index];
	}
	arr1[size1] = '\0';

	//Output String2
	cout<<"\nString2 is:";
	for(index = 0; index < size2; index++)
	{
		cout<<arr2[index];
	}
	arr2[size2] = '\0';
	
	//Concatenate both the strings
	index = 0;
	while(arr1[index] != '\0')
	{
		arr3[index] = arr1[index];
		index++;
	}

	int index_1 = 0;
	while(arr2[index_1] != '\0')
	{
		arr3[index++] = arr2[index_1++];
	}

	arr3[index] = '\0';

	cout<<"\nConcatenated string is:";
	for(index = 0; index < (size1 + size2); index++)
	{
		cout<<arr3[index];
	}

	cout<<"\n";
 }

void q6()
{
	int *ptr;
	int a = 10;

	//Playing around with pointers
	ptr = &a;
	cout<<"Value of ptr is:"<<ptr;
	cout<<"\nValue of &ptr is:"<<&ptr;
	cout<<"\nValue of *ptr is:"<<*ptr;
	cout<<"\nAddress of a is:"<<&a;

	//Playing around with pointer to a pointer
	cout<<"\n\n";
	int **pptr;
	pptr = &ptr;
	cout<<"\nAddress of pptr is:"<<&pptr;
	cout<<"\nValue of pptr is:"<<pptr;
	cout<<"\nValue of *pptr is:"<<*pptr;
	cout<<"\nValue of **pptr is:"<<**pptr;

	//What is the practical application of a pointer to a pointer?

}

void q7()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	cout<<"Size of the array arr is:"<<sizeof(arr);
	cout<<"\nSize of integer on the machine is:"<<sizeof(int);
	cout<<"\nNumber of elements in arr is:"<<sizeof(arr)/sizeof(int);
	cout<<"\n";

	//Compute number of elements of an array in case the type of array is not known
	cout<<"\n\nSize of the array is:"<<sizeof(arr)/sizeof(arr[0]);
	cout<<"\n";

	cout<<"\nSize of character is:"<<sizeof(char);
	cout<<"\nsize of float is:"<<sizeof(float);
	
	char ch[3] = {'s','o','m'};
	char ch_1 = 's';
	char ch_2[5] = "somy"; //It takes NULL by itself. We cannot give 5 characters here.
	//'somy' is a wrong assignment for a character array. Put in double quotes or use CSV.

	cout<<"\nSize of ch is:"<<sizeof(ch);
	cout<<"\nSize of ch_1 is:"<<sizeof(ch_1);
	cout<<"\nSize of ch_2 is:"<<sizeof(ch_2);
	
	cout<<"\n";
}

void q8()
{
	char str[100];
	int index = 0;

	cout<<"\nEnter a string of maximum 100 characters:\n";
	for(index = 0; index <100; index++)
	{
		cin.get(str[index]);
		if(str[index] == '\n')
			break;
	}
	str[index] = '\0'; //Putting Null on the last

	int count = 0;
	index = 0;
	cout<<"\nThe entered string is:";
	while(str[index] !='\0')
	{
		cout<<str[index++];
		count++;
	}
	cout<<"\nLength of the string without using strlen is:"<<count;

	int count_1 = 0;
	count_1 = strlen(str);
	cout<<"\nLength of the string with strlen is:"<<count_1;
}

void q9()
{
	char *str1 = "Somya";
	char *str2 = "Saurabh";

	cout<<"\nString1 is:"<<str1;
	cout<<"\nString2 is:"<<str2;

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	cout<<"\nLength of string1 is:"<<len1;
	cout<<"\nLength of string2 is:"<<len2;

	int len3 = len1 + len2 + 1;
	char *str3 = new char(len3);

	/*str3[0] = '\0';
	strcat(str3,str1);
	strcat(str3,str2);
	cout<<"\n\nThe concatentated string is:"<<str3;
	*/

	int index = 0;
	for(index = 0; index < len1; index++)
	{
		str3[index] = str1[index];
	}

	for(int index_1 = 0; index_1 < len2 ; index_1++)
	{
		str3[index++] = str2[index_1];
	}

	str3[len3 - 1] = '\0';
	cout<<"\n\nThe concatentated string is:"<<str3;

	delete str3;
}

void q10()
{
	int flag = 1;
	char input;
	int size = 1; //No. of characters including terminating char in p at any point
	int index = 1;

	char *p = new char;
	p[0] = '\0';

	cout<<"\nEnter a string to begin with:";
	while(flag)
	{
		cin.get(input);
		if(input != '\n')
		{
			char *temp = new char[size + 1];
			for(index = 0; index < size - 1; index++)
			{
				temp[index] = p[index];
			}

			temp[size - 1] = input;
			temp[size] = '\0';
		
			delete p;
			p = temp;
			size += 1;
		}
		else
		{
			flag = 0;
			cout<<"\nUser is done entering the string!";
			cout<<"\nEntered string is:";
			for(index = 0; index < size-1; index++)
			{
				cout<<p[index];
			}
			break;
		}
	}
}


void q11()
{
	int arr[3] = {1,2,3};
	int *p;
	int index = 0;

	p = &arr[0];

	cout<<"\nValue of elements are:";
	for(index = 0; index < 3; index++)
	{
		cout<<*p;
		p++;
	}
}

void q12()
{
	struct student
	{
		int age;
		int marks;
		char name[20];
		int sno;
	};

	struct student s;
	struct student *ptr;

	cout<<"\nEnter age of the student:";
	cin>>s.age;

	cout<<"\nEnter marks of the student:";
	cin>>s.marks;

	cout<<"\nDetails are: Age and Marks:";
	cout<<s.age<<" "<<s.marks;

	ptr = &s;
	cout<<"\nEnter the name of student:";
	cin>>ptr->name;

	cout<<"\nEnter the sno of the student";
	cin>>ptr->sno;

	cout<<"\nDetails are name and sno:";
	cout<<ptr->name<<" "<<ptr->sno;

}

void q13()
{
	int arr[3] = {7,8,9};
	int *p[3];
	int index = 0;

	p[0] = &arr[0];
	p[1] = &arr[1];
	p[2] = &arr[2];

	cout<<"\nValue of elements are:";
	for(index = 0; index < 3; index++)
	{
		cout<<*p[index];
	}
}

void q14()
{
	int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int *p[3];

	p[0] = &arr[0][0];
	p[1] = &arr[1][0];
	p[2] = &arr[2][0];

	for(int i = 0; i < 3; i++)
	{
		for(int index = 0; index < 3; index++)
		{
			cout<<*(p[i]);
			p[i]++;
		} 
		cout<<"\n";
	}

}

void q15()
{
	struct ll
	{
		int num;
		struct ll *next;
	};

	struct ll *start = NULL;
	struct ll *node, *temp;
	int range;
	int index = 1;

	cout<<"\nEnter a range to traverse the linked list:";
	cin>>range;

	int size = sizeof(struct ll);
	cout<<"\nSize is:"<<size;

	node = new struct ll();
	node->num = index;
	node->next = NULL;

	start = node;
	temp = node;

	for(index = 2; index <= range; index++)
	{
		node = new struct ll();
		node->num = index;
		node->next = NULL;

		temp->next = node;
		temp = node;
	}

	//Tried to print using start to verify that it stored everything.
	//Do not traverse by start, not a good practice.
	cout<<"\nTraversing the whole linked list:";
	while(start != NULL)
	{
		cout<<start->num<<"->";
		start = start->next;
	}
}

void q16()
{
	//Pointer to a string example
	char *strings = "somya";
	int index;

	cout<<"Value pointed by strings is:"<<strings<<"\n";
	
	//Printing Element by Element
	cout<<"\nNow printing character by character:";
	for(index = 0; index < 5; index++)
	{
		cout<<*strings++ <<" ";
	}

	//Array of pointers to strings
	char *names[3] = {"somya","saurabh","testing"};
	
	cout<<"\n\nNames pointed by the strings are: ";
	for(index = 0; index < 3; index++)
	{
		cout<<names[index]<<" ";
	}

	int len = strlen(names[1]);
	cout<<"\nLength of Saurabh is:"<<len<<"\n";

	cout<<"\nNow printing character by character:";
	for(index = 0; index < len; index++)
	{
		cout<< *names[1]++ <<" ";
	}
}

class test
{
private:
	int a1;
public:
	test(int a)
	{
		a1 = a;
	}
	void print()
	{
		cout<<"\nValue of a1 is:"<<a1;
	}
};

void q17()
{
	test t(5);
	t.print();

	test *t1 = new test(10);
	t1->print();

	char cc = 65;
	cc = 'A';
	int a;
	a = (int)cc;
	cout<<"\nValue of a after type conversion is:"<<a;

	char *ch = new char('A');
	cout<<"\nValue of ch is:"<<*ch;
}

/*Implement Doubly Linked List using classes and implement all operations using O(1)*/
struct doubly_ll
{
	int index;
	struct doubly_ll *prev, *next;
};
class doublyLinkedList
{
public:
	doubly_ll *start;
	doubly_ll *last;

	doublyLinkedList(int range)
	{
		int index;
		start = NULL;
		last = NULL;

		for(index = 1; index<= range; index++)
		{
			doubly_ll *temp = new doubly_ll;
			temp->index = index;
			temp->prev = NULL;
			temp->next = NULL;

			//Condition for first node in the list
			if(start == NULL)
			{
				start = temp;
				last = temp;
			}
			else
			{
				last->next = temp;
				temp->prev = last;
				last = temp;
			}
		}
	}

	void print()
	{
		doubly_ll *temp;
		temp = start;

		cout<<"Linked List is:";
		while(temp != NULL)
		{
			cout<<temp->index<<" ";
			temp = temp->next;
		}
	}

	void insertBegin(int value)
	{
		doubly_ll *temp = new doubly_ll();
		temp->index = value;
		temp->prev = NULL;
		temp->next = NULL;

		temp->next = start;
		start->prev = temp;
		start = temp;
	}

	void insertLast(int value)
	{
		doubly_ll *temp = new doubly_ll();
		temp->index = value;
		temp->prev = NULL;
		temp->next = NULL;

		last->next = temp;
		temp->prev = last;
		last = temp;
	}

	void deleteBegin()
	{
		doubly_ll *temp;
		temp = start;

		start = start->next;
		start->prev = NULL;

		temp->next = NULL;
		delete temp;
	}

	void deleteLast()
	{
		doubly_ll *temp;
		temp = last;

		last = last->prev;
		last->next = NULL;

		temp->prev = NULL;
		delete temp;
	}

	~doublyLinkedList()
	{
		doubly_ll *temp;

		while(start != NULL)
		{
			temp = start;
			start = start->next;
			delete temp;
		}
	}
};

void doublell()
{
	doublyLinkedList d(15);
	d.print();

	cout<<"\n";
	d.insertBegin(0);
	d.insertLast(16);
	d.print();

	cout<<"\n";
	d.deleteBegin();
	d.deleteBegin();
	d.print();

	cout<<"\n";
	d.deleteLast();
	d.print();
}

/*
Today's assignment(02/11/2015)
@Class LinkedList
@m1: LinkedList(int range): create a linked list having int nodes from 1 till range
@m2: insertNodesInBetween(): inserts a new node after every node in the linked list with some int value(take some sensible value)
@m3: printLinkedList(): it will print the linked list
*/

struct ll
{
	int num;
	struct ll *next;
};

class linkedList
{
public:
	ll *start;
	ll *last;			//pointing to last node

	linkedList(int range)
	{
		start = NULL;
		last = NULL;
		ll **prev_p = &start;

		for(int index = 1; index <= range; index++)
		{
			//create a new node
			ll *node = new ll();
			node->num = index;
			node->next = NULL;

			//assign the prev pointer to this newly created node
			*prev_p = node;
			prev_p = &(node->next);
			last = node;
		}
	}

	int nodeCount()
	{
		struct ll *node;
		int count = 0;

		node = start;
		while(node != NULL)
		{
			count++;
		}
		return count;
	}

	void insertNodesInBetween()
	{
		int count = nodeCount();
		if(count >=2)
		{
			struct ll *temp;
			int index = 100;

			temp = start;

			while(temp->next != NULL)
			{
				struct ll *node = new struct ll(); //It is the new node which will get inserted

				node->num = index;
				node->next = temp->next;
				temp->next = node;

				temp = temp->next->next;
				index = index + 100;
			}
		}
		else
		{
			cout<<"\nAtleast two nodes are needed to insert in between!";
		}
	}

	void print()
	{
		struct ll *temp;
		temp = start;

		while(temp != NULL)
		{
			cout<<temp->num<<" ";
			temp = temp->next;
		}
	}

	void pushBack(int value)
	{
		struct ll *node = new struct ll();
		node->num = value;
		node->next = NULL;

		last->next = node;
		last = node;
	}

	void pushFront(int value)
	{
		struct ll *node = new struct ll();
		node->num = value;
		node->next = NULL;

		node->next = start;
		start = node;
	}

	void deleteFront()
	{
		struct ll *temp;
		temp = start;

		start = start->next;
		delete temp;
	}

	void deleteLast()
	{
		struct ll *temp, *temp1;
		temp = start;
		temp1 = start->next;

		while(temp1->next != NULL)
		{
			temp = temp->next;
			temp1 = temp1->next;
		}

		temp->next = NULL;
		delete temp1;
	}

	~linkedList()
	{
		cout<<"\n--Calling Destructor!--\n";
		struct ll *temp;
		while(start != NULL)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
};

void q18()
{
	/*Class LinkedList*/
	
	cout<<"\nLink List initially is:\n";
	linkedList l_obj(10);
	l_obj.print();

	cout<<"\n\nLinked List after inserting nodes in between:\n";
	l_obj.insertNodesInBetween();
	l_obj.print();

	cout<<"\n\n";

	cout<<"\nLinked list using pointer object is:";
	linkedList *l_obj1 = new linkedList(10);
	l_obj1->print();

	delete l_obj1;
	
	/*Class LinkedList*/
}

void q21()
{
	cout<<"Linked list initially is:";
	linkedList l(10);
	l.print();

	cout<<"\n\nLinked List after insertion in the end is:";
	l.pushBack(11);
	l.print();

	cout<<"\n\nLinked list after insertion in the beginning is:";
	l.pushFront(0);
	l.print();

	l.pushBack(12);
	l.pushBack(13);
	l.pushFront(1990);

	cout<<"\n\n\nLinked list now is:";
	l.print();

	cout<<"\n\nLinked list after first node deletion is:";
	l.deleteFront();
	l.print();

	cout<<"\n\nLinked list after last node deletion is:";
	l.deleteLast();
	l.deleteLast();
	l.print();

}



/*
write functions:
F1: createCharArray(...): takes an integer and returns a char pointer of integer array size
F2: multipleInt(...): modifies an integer variable in the argument and multiply it by 10. 
The passed integer in argument should be mutated in the function.
*/

char* createCharArray(int size)
{
	return new char[size];
}

void q19()
{
	/*Body code for createCharArray*/
	
	char *ch;
	int index;
	ch = createCharArray(10);

	for(index = 0; index <10; index++)
	{
		ch[index] = 'a' + index;
	}

	cout<<"\nValue in the allocated array is:";
	for(index = 0; index <10; index++)
	{
		cout<<ch[index]<<" ";
	}
	/*Body code ends for createCharArray*/
}

void multipleInt(int *num)
{
	*num = *num * 10; 
}

void q20()
{
	/*Body  code for multipleInt*/
	int a = 2;
	multipleInt(&a);
	cout<<"\nValue of Input is:"<<a;
	/*Body of multipleInt*/
}

int main_temp()
{
	doublell();
	cout<<"\n";
	return 0;
}











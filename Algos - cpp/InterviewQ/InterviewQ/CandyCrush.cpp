/* It displays a grid of candies (chars) and will tell the user the maximum number of candies that can come togther in up/down/left/right 
direction by moving a candy in either of the positions. */

#include<iostream>
#include<string>
#include<time.h>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX_ROW 10
#define MAX_COL 10

//checks for the max consective locations for a given value; it takes the modified arr in which a candy is swapped left/right/up/down
int checkConsecutive(int val, int row, int col, int arr[MAX_ROW][MAX_COL])
{
	int Hcount = 1;
	int Vcount = 1;

	int rc = row;
	int cc = col;

	while((rc <= MAX_ROW - 1) && (val == arr[++rc][col]))
		Vcount++;

	rc = row;
	while((val == arr[--rc][col]) && (rc >= 0))
		Vcount++;

	while((val == arr[row][++cc]) && (cc <= MAX_COL - 1))
		Hcount++;

	cc = col;
	while((val == arr[row][--cc]) && (cc >= 0))
		Hcount++;

	return max(Hcount, Vcount);
}

void swap_val(int val1, int val2){
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

//returns the max number of same candies if you swap candy at i,j to one in the left
int checkLeft(int row, int col, int arr[MAX_ROW][MAX_COL])
{
	//No left movement possible
	if(col == 0)
		return 0;

	int val = arr[row][col];

	//Swap the current candy to the one on its left
	swap(arr[row][col], arr[row][col - 1]);

	int count = (checkConsecutive(val, row, col - 1,arr));

	//swap them back
	swap(arr[row][col], arr[row][col - 1]);

	//cout<<",Left:"<<count;
	return count;
}

//returns the max number of same candies if you swap candy at i,j to one in the right
int checkRight(int row, int col,  int arr[MAX_ROW][MAX_COL])
{
	//No right movement possible
	if(col == MAX_COL - 1)
		return 0;

	int val = arr[row][col];

	//Swap the candy to the one on its right
	swap(arr[row][col], arr[row][col + 1]);

	int count = (checkConsecutive(val, row, col + 1, arr));

	//swap them back
	swap(arr[row][col], arr[row][col + 1]);

	//cout<<",Right:"<<count;
	return count;
} 

//returns the max number of same candies if you swap candy at i,j to one in the up
int checkUp(int row, int col,  int arr[MAX_ROW][MAX_COL])
{
	if(row == 0)
		return 0;

	int val = arr[row][col];

	//Swap it with the candy on its up
	swap(arr[row][col], arr[row - 1][col]);

	int count = (checkConsecutive(val, row - 1, col, arr));

	//swap them back
	swap(arr[row][col], arr[row - 1][col]);

	//cout<<",Up:"<<count;
	return count;
}


//returns the max number of same candies if you swap candy at i,j to one in the down
int checkDown(int row, int col,  int arr[MAX_ROW][MAX_COL])
{
	if(row == MAX_ROW - 1)
	{
		//cout<<"\n\ni:"<<row<<" ,j:"<<col<<", Down:0";
		return 0;
	}

	int val = arr[row][col];

	//swap with the candy on its down
	swap(arr[row][col], arr[row + 1][col]);

	//check the max consecutive candies now for this new matrix
	int count = checkConsecutive(val, row+ 1, col, arr);
	
	//swap back them now to restore the original array
	swap(arr[row][col], arr[row + 1][col]);

	//cout<<"\n\ni:"<<row<<" ,j:"<<col<<", Down:"<<count;
	return count;

}


//this defines a candy move
struct candyMove {
	candyMove(int x, int y, string s):srcRow(x), srcCol(y), Movement(s) {}

	int srcRow;								//src row of the candy
	int srcCol;								//src col of the candy
	string Movement;
};

candyMove bestMove(0, 0, "MoveDown");
int candiesCrushed = 0;


void setBestMove(candyMove newMove, int candiesCrushedByNewMove) {
	if (candiesCrushedByNewMove >= candiesCrushed) {
		candiesCrushed = candiesCrushedByNewMove;
		bestMove = newMove;
	}
}

int main_candy()
{
	int countLeft, countRight, countUp, countDown;
	int count,flag;

	int maxCount, maxRow, maxCol, maxFlag;

	int arr[MAX_ROW][MAX_COL] = {0};
	int random;

	srand (time(NULL));
	//Remove the duplicates such that no more than 3 are formed in a row or column
	for(int i = 0; i < MAX_ROW; i++)
	{
		for(int j=0; j<MAX_COL; j++)
		{
			random = rand() % 5 + 1;
			arr[i][j] = random;
		}
	}

	cout<<"  ";
	for(int i=0; i<10; i++)
		cout<<i<<" ";

	cout<<"\n\n";

	char c;
	for(int i = 0; i < MAX_ROW; i++)
	{
		cout<<i<<" ";
		for(int j=0; j<MAX_COL; j++)
		{
			c = arr[i][j] + 'a';
			cout<<c<<" ";
		}
		cout<<"\n\n";
	}

	int candiesCrush = 0;
	for(int i = 0; i < MAX_ROW; i++)
	{
		for(int j=0; j < MAX_COL; j++)
		{
			candiesCrush = checkDown(i,j, arr);
			setBestMove(candyMove(i, j, "MoveDown"), candiesCrush);

			candiesCrush = checkUp(i,j, arr);
			setBestMove(candyMove(i, j, "MoveUp"), candiesCrush);

			candiesCrush = checkLeft(i,j,arr);
			setBestMove(candyMove(i, j, "MoveLeft"), candiesCrush);

			candiesCrush = checkRight(i,j, arr);
			setBestMove(candyMove(i, j, "MoveRight"), candiesCrush);
		}
	}

	cout<<"\n\nThe longest move is of length: "<<candiesCrushed<<" at row: "<<bestMove.srcRow<<" , col: "<<bestMove.srcCol<<" by movement: "<<bestMove.Movement;
	return 0;
}
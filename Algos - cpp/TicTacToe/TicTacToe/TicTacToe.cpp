#include"TicTacToe.h"
#include<iostream>
#include<vector>
using namespace std;

TicTacToe::TicTacToe()
{
	for(int index = 0; index < 9; index++)
		matrix.push_back(5);
}

void TicTacToe::printMatrix()
{
	for(int index = 0; index < 9; index++)
	{
		if(index % 3 == 0)
			cout<<"\n\n";

		if(matrix[index] == 5)
			cout<<"-"<<index<<"-"<<"\t";
		else if(matrix[index] == 3)
			cout<<"0"<<"\t";
		else
			cout<<"X"<<"\t";
	}
}

int TicTacToe::checkIsEmpty(int location)
{
	//1 is for empty location
	if(matrix[location] == 5)
		return true;
	else
		return false;
}

void TicTacToe::updateMatrix(int location, int player)
{	
	if(player == 1)
		matrix[location] = 3;
	else
		matrix[location] = 2;
}

int TicTacToe::isLocationValid(int location)
{
	if(location>= 0 && location <= 8)
	{
		int check;
		check = checkIsEmpty(location);
		if(!check)
		{
			cout<<"\nLocation not empty! Choose another.";
			return false;
		}
	}
	else
	{
		cout<<"\nInvalid Location! Choose another.";
		return false;
	}
}

bool TicTacToe::checkHorizontally(int location)
{
	int row, value, value1, value2, index;

	row = location / 3;
	index = row * 3;
	
	//values at the current row location
	value = matrix[index];
	value1 = matrix[index + 1];
	value2 = matrix[index + 2];

	return whoWins(value, value1, value2) > 0;
}

//returns 0 if no one wins, 1 if x wins and 2 if O wins
int TicTacToe::whoWins(int val1, int val2, int val3) {
	int mul = val1 * val2 * val3;
	if(mul == 8)
		return 1;
	else if(mul == 27)
		return 2;
	else
		return 0;
}

bool TicTacToe::checkVertically(int location)
{
	int col;
	col = location % 3;
	
	//values at the current column location
	int value = matrix[col];
	int value1 = matrix[col + 3];
	int value2 = matrix[col + 6];

	return whoWins(value, value1, value2) > 0;
}

bool TicTacToe::checkAcross(int location)
{
	//for current location, no across can be made, so its either 1,3,5,7.
	//Return from here only rather than checking further
	if(location % 2 != 0)
		return false;
	else
	{
		//checking for left diagnol
		int l_d = 0;
		int l_d1 = l_d + 4;
		int l_d2 = l_d + 8;

		l_d = matrix[l_d];
		l_d1 = matrix [l_d1];
		l_d2 = matrix[l_d2];

		int flag = whoWins(l_d,l_d1,l_d2);
		if(flag > 0)
			return true;

		//checking for right diagnol
		int r_d = 2;
		int r_d1 = r_d + 2;
		int r_d2 = r_d + 4;

		r_d = matrix[r_d];
		r_d1 = matrix [r_d1];
		r_d2 = matrix[r_d2];

		return whoWins(r_d,r_d1,r_d2) > 0;
	}
}

bool TicTacToe::checkWin(int location)
{
	return (checkHorizontally(location) || checkVertically(location) || checkAcross(location));
}

bool TicTacToe::checkIfFull()
{ 
	bool flag = 0;
	for(int index = 0; index <9; index++)
	{
		//check if any space is empty
		if(matrix[index] == 5)
			flag = 1;
	}
	if(flag)
		return false;
	else 
		return true;
}
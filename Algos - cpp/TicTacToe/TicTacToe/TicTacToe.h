#ifndef TicTacToe_H
#define TicTacToe_H

using namespace std;
#include<vector>

class TicTacToe
{
private:
	//return true if the location is empty else returns false
	int checkIsEmpty(int location);

	
	//stores the location of the tic toe game by index (0-8) mapped by the values:
	//1- empty; 2- '0'; 3-'X'
	vector<int>matrix;

	//checks for win condition horizontally
	bool checkHorizontally(int location);

	//checks for win condition vertically
	bool checkVertically(int location);

	//checks for win condition across
	bool checkAcross(int location);

	int whoWins(int val1, int val2, int val3);

public:
	//checks for win condition considering all angles
	bool checkWin(int location);

	//checks if the board is full and game should be over
	bool checkIfFull();

	//initailses the matrix with 1, means all locations are empty
	TicTacToe();

	//prints the game in the form of the matrix
	void printMatrix();

	//checks if the entered location by the user is valid or not
	int isLocationValid(int location);

	//Updates the vector matrix as per the incoming location from the user
	void updateMatrix(int location, int player);
};

#endif
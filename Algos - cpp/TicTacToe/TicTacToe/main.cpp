#include<iostream>
#include"TicTacToe.h"
using namespace std;

void main()
{
	int location;
	int count = 0;
	TicTacToe t_obj;
	bool check, flag = 0, full = 0;
	int player = 1;

	cout<<"Welcome to game of TIC TAC TOE";
	cout<<"\n\nPlayer 1 will fill 'O', Player 2 will fill 'X'";
	t_obj.printMatrix();

	while((!flag) && (!full))
	{
		cout<<"\n\nEnter location for player "<<(player)<<":";
		cin>>location;
		check = t_obj.isLocationValid(location);
		if(!check) {
			cout <<"Enter a valid position\n;";
			continue;
		}
		t_obj.updateMatrix(location, player);
		t_obj.printMatrix();
		
		flag = t_obj.checkWin(location);
		full = t_obj.checkIfFull();

		player = (player == 1 ? 2 : 1);
	}

	if(full)
		cout<<"\nGame Over, Board full, None wins!";
	else
	{
		player = (player == 1 ? 2 : 1);
		cout<<"\nGame over! Player "<<player<<" Wins!";
	}
}
#include "stdafx.h"
#include "TicTacToeGame.h"

int main()
{
	cout << "Welcome to Tic Tac Toe Game." << endl << endl;

	TicTacToeGame game;
	game.StartGame();

	//show the winner
	game.DisplayWiner();

	system("PAUSE");

	return 0;
}
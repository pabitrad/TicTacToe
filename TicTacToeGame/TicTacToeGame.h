#pragma once
#include <iostream>
#include <ctime>

#include "Board.h"
#include "Player.h"
#include "Helper.h"

class TicTacToeGame
{
public:
	TicTacToeGame();
	TicTacToeGame(const Board& board);

	void StartGame();
	void DisplayWiner();

	//Followings made public because of automated unit tests
	PLAYER_ID WhoWon();
	bool IsValidMove(int cellNo);

private:
	PLAYER_ID _whosTurn = PLAYER_ID::PLAYER_1;

	Board _board;
	Player _player1;
	Player _player2;

	void EnterPlayerNames();
};


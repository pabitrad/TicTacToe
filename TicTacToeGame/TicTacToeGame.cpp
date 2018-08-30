#include "stdafx.h"
#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame():_whosTurn(PLAYER_ID::PLAYER_1)
{
	_player1.Id = PLAYER_ID::PLAYER_1;
	_player2.Id = PLAYER_ID::PLAYER_2;
}

//This one used in test cases
TicTacToeGame::TicTacToeGame(const Board& gameBoard):TicTacToeGame()
{
	_board = gameBoard;
}

void TicTacToeGame::EnterPlayerNames()
{
	// Get player names
	cout << "Player 1: Please enter your name." << endl;
	cin >> _player1.Name;

	cout << "Player 2: Computer." << endl;
	cin >> _player2.Name;
}

bool TicTacToeGame::IsValidMove(const int cellNo)
{
	int row = cellNo / Board::MAX_DIM;
	int col = cellNo % Board::MAX_DIM;

	if (cellNo >= 0 &&
		cellNo < (Board::MAX_DIM)*(Board::MAX_DIM) &&
		_board.GetSpotValue(row, col) != 'x' &&
		_board.GetSpotValue(row, col) != 'o')
	{
		return true;
	}
	else
	{
		cout << "Invalid spot." << endl;
	}

	return false;
}

// Return player ID
PLAYER_ID TicTacToeGame::WhoWon()
{
	//Check horizontal rows if any of these equal spot values
	for (int i = 0; i < Board::MAX_DIM; i++)
	{
		bool horizontal = true;
		for (int j = 1; j < Board::MAX_DIM; j++)
		{
			//if all horintal are equal
			if (_board.GetSpotValue(i, j - 1) != _board.GetSpotValue(i, j))
			{
				horizontal = false;
				break;
			}
		}
		if (horizontal == true)
		{
			return GameHelper::CharToWinner(_board.GetSpotValue(i, 0));
		}
	}

	//Check vertical columns if any of these equal spot values
	for (int i = 0; i < Board::MAX_DIM; i++)
	{
		bool vertical = true;
		for (int j = 1; j < Board::MAX_DIM; j++)
		{
			if (_board.GetSpotValue(j - 1, i) != _board.GetSpotValue(j, i))
			{
				vertical = false;
				break;
			}
		}
		if (vertical == true)
		{
			return GameHelper::CharToWinner(_board.GetSpotValue(0, i));
		}
	}

	bool diagonal = true;
	//Check for diagonal values like (0,0), (1,1), (2,2) etc
	for (int i = 0; i < Board::MAX_DIM - 1; i++)
	{
		if (_board.GetSpotValue(i, i) != _board.GetSpotValue(i + 1, i + 1))
		{
			diagonal = false;
			break;
		}
	}

	if (diagonal == true)
	{
		return GameHelper::CharToWinner(_board.GetSpotValue(0, 0));
	}

	diagonal = true;
	int i, j;
	//Check for other diagonal values (2,0), (1,1), (0,2)
	for (i = Board::MAX_DIM - 1, j = 0; j < Board::MAX_DIM - 1; i--, j++)
	{
		if (_board.GetSpotValue(i, j) != _board.GetSpotValue(i - 1, j + 1))
		{
			diagonal = false;
			break;
		}
	}

	if (diagonal == true)
	{
		return GameHelper::CharToWinner(_board.GetSpotValue(Board::MAX_DIM - 1, 0));
	}

	return NONE;
}


void TicTacToeGame::StartGame()
{
	srand(time(NULL));
	int totalMoves = 0;
	EnterPlayerNames();

	int nMove;
	const int maxCells = Board::MAX_DIM * Board::MAX_DIM;
	while (WhoWon() == PLAYER_ID::NONE && totalMoves < maxCells)
	{
		do
		{
			if (_whosTurn == PLAYER_1) {
				// Show the board
				_board.Show();

				nMove = _player1.Move();
			}
			else {
				// Computer selects random spot
				nMove = rand() % (maxCells);
			}
		} while (IsValidMove(nMove) == false);

		totalMoves++;
		int row = nMove / Board::MAX_DIM;
		int col = nMove % Board::MAX_DIM;

		switch (_whosTurn) {
			case (PLAYER_1):
				
				_board.SetSpotValue(row, col, 'x');
				_whosTurn = PLAYER_2;
				break;

			case (PLAYER_2):
				_board.SetSpotValue(row, col, 'o');
				_whosTurn = PLAYER_1;
			}
	}

	// Show the board
	_board.Show();
}

void TicTacToeGame::DisplayWiner()
{
	switch (WhoWon()) {
		case PLAYER_1:
			cout << _player1.Name << " has won the game!" << endl << endl;
			break;

		case PLAYER_2:
			cout << _player2.Name << " has won the game!" << endl << endl;
			break;

		default:
			cout << "It's a tie game!" << endl << endl;
			break;
	}
}
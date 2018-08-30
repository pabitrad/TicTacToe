#include "stdafx.h"
#include "Board.h"

Board::Board()
{
	_matrix = new char*[MAX_DIM];
	for (int i = 0; i < MAX_DIM; i++)
	{
		_matrix[i] = new char[MAX_DIM];
	}
	
	InitializeBoard();
}

void Board::Show()
{
	for (int i = 0; i < MAX_DIM; ++i)
	{
		for (int j = 0; j < MAX_DIM; ++j)
		{
			cout << _matrix[i][j] << " | ";
		}
		cout << endl;
		cout << "--+---+--" << endl;		
	}
}


void Board::InitializeBoard()
{
	char k = '0';
	for (int i = 0; i < MAX_DIM; ++i)
	{
		for (int j = 0; j < MAX_DIM; ++j)
		{
			_matrix[i][j] = k++;
		}
	}
	/*_matrix[0] = '0';
	_matrix[1] = '1';
	_matrix[2] = '2';
	_matrix[3] = '3';
	_matrix[4] = '4';
	_matrix[5] = '5';
	_matrix[6] = '6';
	_matrix[7] = '7';
	_matrix[8] = '8';*/
}

void  Board::operator = (const Board &board) {

	_matrix = new char*[board.MAX_DIM];
	for (int i = 0; i < board.MAX_DIM; i++)
	{
		_matrix[i] = new char[board.MAX_DIM];
	}

	for (int i = 0; i < MAX_DIM; ++i)
	{
		for (int j = 0; j < MAX_DIM; ++j)
		{
			_matrix[i][j] = board._matrix[i][j];
		}
	}
}

 Board::~Board()
{
	delete[] _matrix;
}
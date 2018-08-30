#pragma once
#include <iostream>

using namespace std;

class Board
{
public:
	Board();
	~Board();
	static const int MAX_DIM = 3;
	void Show();

	char GetSpotValue(int i, int j)
	{
		return _matrix[i][j];
	}

	void SetSpotValue(int i, int j, char value)
	{
		_matrix[i][j] = value;
	}

	void operator = (const Board &board);

private:
	
	char** _matrix;		
	void InitializeBoard();
};


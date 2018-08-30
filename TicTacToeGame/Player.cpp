#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	Id = NONE;
}


Player::~Player()
{
}

int Player::Move()
{
	int nMove;

	cout << Name << ": It's your turn." << endl;
	// Get the move
	cout << "Enter the number of the spot(from 0 to 8) where you'd like to move." << endl;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> nMove;

	return nMove;
}
#pragma once
#include <string>
#include <iostream>

using namespace std;

enum PLAYER_ID
{
	NONE = 0,
	PLAYER_1 = 1,
	PLAYER_2 = 2
};

class Player
{
public:
	PLAYER_ID Id;
	string Name;

	Player();
	~Player();
	int Move();
};


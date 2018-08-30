#pragma once
#include "player.h"

class GameHelper
{
	public:
		static PLAYER_ID CharToWinner(char ch)
		{
			if (ch == 'x') {
				return PLAYER_1;
			}
			else {
				return PLAYER_2;
			}
		}
};
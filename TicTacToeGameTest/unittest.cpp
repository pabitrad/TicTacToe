//#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TicTacToeGame/Board.h"
#include "../TicTacToeGame/TicTacToeGame.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TicTacToeGameTest
{		
	TEST_CLASS(UnitTestTicTacToe)
	{
		public:
			//Testing for game board initial values
			//TEST_METHOD(TestMethodBoardInitialize)
			//{
			//	Board gameBoard;

			//	Assert::IsTrue(gameBoard[0] == '0' && gameBoard[1] == '1' && gameBoard[2] == '2' &&
			//		gameBoard[3] == '3' && gameBoard[4] == '4' && gameBoard[5] == '5' &&
			//		gameBoard[6] == '6' && gameBoard[7] == '7' && gameBoard[8] == '8'
			//	);
			//}

			// Valid move by player
			TEST_METHOD(TestMethodValidMove)
			{
				TicTacToeGame game;
				bool moveStatus = game.IsValidMove(3);

				Assert::IsTrue(moveStatus);
			};

			// Invalid move by player
			TEST_METHOD(TestMethodInvalidMove)
			{
				TicTacToeGame game;
				bool moveStatus = game.IsValidMove(9);

				Assert::IsFalse(moveStatus);
			};

			//Test WhoWon() method
			//Player 1 won the game
			TEST_METHOD(TestMethodPlayerOneWon)
			{
				Board gameBoard;
				gameBoard.SetSpotValue(0, 0, 'x');
				gameBoard.SetSpotValue(0, 1, 'x');
				gameBoard.SetSpotValue(0, 2, 'x');
				gameBoard.SetSpotValue(1, 0, 'o');
				gameBoard.SetSpotValue(1, 1, 'o');

				TicTacToeGame game(gameBoard);
				Assert::IsTrue(game.WhoWon() == PLAYER_ID::PLAYER_1);
			}

			//Test WhoWon() method
			//Player 1 won the game
			//TEST_METHOD(TestMethodPlayerTwoeWon)
			//{
			//	Board gameBoard;
			//	gameBoard[1] = 'x';
			//	gameBoard[3] = 'x';
			//	gameBoard[5] = 'x';

			//	gameBoard[0] = 'o';
			//	gameBoard[4] = 'o';
			//	gameBoard[8] = 'o';

			//	TicTacToeGame game(gameBoard);
			//	Assert::IsTrue(game.WhoWon() == PLAYER_ID::PLAYER_2);
			//}
	};


}
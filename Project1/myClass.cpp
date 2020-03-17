#include "myClass.h"
#include "CMinMax.h"





myClass::myClass()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			gameBoard[i][j] = '-';
		}
	}
}

myClass::~myClass()
{

}

void myClass::PrintBoard()
{
	cout << endl;
	cout << "	,-----------------------------------------,	" << endl;
	cout << "	`-----------------------------------------' " << endl;
	cout << "	  |                                     |   " << endl;
	cout << "	  |      [ " << gameBoard[0][0] << " ]      [ " << gameBoard[0][1] << " ]      [ " << gameBoard[0][2] << " ]    |   " << endl;
	cout << "	  |                                     |   " << endl;
	cout << "	  |      [ " << gameBoard[1][0] << " ]      [ " << gameBoard[1][1] << " ]      [ " << gameBoard[1][2] << " ]    |   " << endl;
	cout << "	  |                                     |   " << endl;
	cout << "	  |      [ " << gameBoard[2][0] << " ]      [ " << gameBoard[2][1] << " ]      [ " << gameBoard[2][2] << " ]    |   " << endl;
	cout << "	  |                                     |   " << endl;
	cout << "	,-----------------------------------------,	" << endl;
	cout << "	`-----------------------------------------' " << endl;
	cout << endl;
}

void myClass::playVSEasy()
{
	bool playersTurn = true;
	bool notWon = true;

	system("CLS");

	while (notWon)
	{
		if (playersTurn)
		{
			char playerToken = 'X';
			system("CLS");
			PrintBoard();

			// Ask player for place location
			int playerRow;
			cout << "Please enter the row you would like to place" << endl;
			cin >> playerRow;
			int playerCol;
			cout << "Please enter the column you would like to place" << endl;
			cin >> playerCol;

			// Check to see if can place at loction
			if (checkBoard(playerRow, playerCol, playerToken) == false)
			{
				system("CLS");
				cout << "Please enter a vaild location" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(1000, '\n');
				playVSEasy();
			}
			else
			{
				placeOnBoard(playerToken, playerRow, playerCol);
				system("CLS");
				playersTurn = false;
			}

			// Checks to see if player has won
			if (winCheck(playerToken))
			{
				system("CLS");
				cout << "Player -  ' " << playerToken << " ' " << " has won the game!" << endl;
				Sleep(1000);
				
				return;
			}

			// Checks to see if the game is a draw
			if (drawCheck())
			{
				system("CLS");
				cout << "Game is a draw" << endl;
				Sleep(2000);
				return;
			}
		}
		else
		{
			bool notPlaced = true;
			char compToken = 'O';

			int RandRow;
			int RandCol;

			srand(time(NULL));

			while (notPlaced)
			{
				// Gets random locations on board
				RandRow = rand() % 4;
				RandCol = rand() % 4;

				// Checks to see if can place at locaiton
				if (checkBoard(RandRow, RandCol, compToken))
				{
					placeOnBoard(compToken, RandRow, RandCol);
					notPlaced = false;
				}
			}

			// Checks to see if comp won
			if (winCheck(compToken))
			{
				system("CLS");
				cout << compToken << " - Computer Wins!" << endl;
				Sleep(1000);
			}

			// Checks to see if the game is a draw
			if (drawCheck())
			{
				system("CLS");
				cout << "Game is a draw" << endl;
				Sleep(2000);
				return;
			}
			
			playersTurn = true;

			// Reset for next round
			notPlaced = true;
		}
	}
}

void myClass::playVSHard()
{
	bool playersTurn = true;
	bool notWon = true;

	while (notWon)
	{
		if (playersTurn)
		{
			char playerToken = 'X';
			system("CLS");
			PrintBoard();

			// Ask player for place location
			int playerRow;
			cout << "Please enter the row you would like to place" << endl;
			cin >> playerRow;
			int playerCol;
			cout << "Please enter the column you would like to place" << endl;
			cin >> playerCol;

			// Check to see if can place at loction
			if (checkBoard(playerRow, playerCol, playerToken) == false)
			{
				system("CLS");
				cout << "Please enter a vaild location" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(1000, '\n');
				playVSEasy();
			}
			else
			{
				placeOnBoard(playerToken, playerRow, playerCol);
				system("CLS");
				playersTurn = false;
			}

			// Checks to see if player has won
			if (winCheck(playerToken))
			{
				system("CLS");
				cout << "Player -  ' " << playerToken << " ' " << " has won the game!" << endl;
				Sleep(1000);

				return;
			}

			// Checks to see if the game is a draw
			if (drawCheck())
			{
				system("CLS");
				cout << "Game is a draw" << endl;
				Sleep(2000);
				return;
			}
		}
		else
		{
			char compToken = 'O';
			system("CLS");
			PrintBoard();

			CMinMax hardAI(gameBoard, compToken);

			int position = hardAI.GetBestMove();
			Vector2D rowCol = hardAIRowCol(position);
			placeOnBoard(compToken, rowCol.x, rowCol.y);


			// Min Max Code needed
		}
	}

}

void myClass::playVSPlay(bool playerOneTurn)
{
	//bool playerOneTurn = true;
	bool notWon = true;

	while (notWon)
	{
		if (playerOneTurn)
		{
			/// Player Ones Turn
			char playerOneToken = 'X';

			system("CLS");

			PrintBoard();
			// Ask player for place location
			int playerOneRow;
			cout << "Player One - Please enter the row you would like to place" << endl;
			cin >> playerOneRow;
			int playerOneCol;
			cout << "Player One - Please enter the column you would like to place" << endl;
			cin >> playerOneCol;

			// Checks to see if can place at location
			if (checkBoard(playerOneRow, playerOneCol, playerOneToken) == false)
			{
				cout << "Please enter a valid location" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(1000, '\n');
				playVSPlay();
			}
			else
			{
				placeOnBoard(playerOneToken, playerOneRow, playerOneCol);
			}

			// Checks to see if player one has won
			if (winCheck(playerOneToken))
			{
				system("CLS");
				cout << "Player One Wins - " << playerOneToken << endl;
				Sleep(1000);
				return;

			}

			// Checks to see if the game is a draw
			if (drawCheck())
			{
				system("CLS");
				cout << "Game is a draw" << endl;
				Sleep(2000);
				return;
			}

			// Clears inputs for the next round
			cin.clear();
			cin.ignore(1000, '\n');
			playerOneTurn = false;
		}
		else
		{
			/// Player Twos Turn
			char playerTwoToken = 'O';

			system("CLS");

			PrintBoard();
			// Ask player two for place location
			int playerTwoRow;
			cout << "Player Two - Please enter the row you would like to place" << endl;
			cin >> playerTwoRow;
			int playerTwoCol;
			cout << "Player Two - Please enter the column you would like to place" << endl;
			cin >> playerTwoCol;

			// Checks to see if can place at location
			if (checkBoard(playerTwoRow, playerTwoCol, playerTwoToken) == false)
			{
				cout << "Please enter a valid location" << endl;
				Sleep(1000);
				cin.clear();
				cin.ignore(1000, '\n');
				playVSPlay(false);
			}
			else
			{
				placeOnBoard(playerTwoToken, playerTwoRow, playerTwoCol);
			}

			// Checks to see if player two has won
			if (winCheck(playerTwoToken))
			{
				system("CLS");
				cout << "Player Two Wins - " << playerTwoToken << endl;
				Sleep(1000);
				return;
			}

			// Checks to see if the game is a draw
			if (drawCheck())
			{
				system("CLS");
				cout << "Game is a draw" << endl;
				Sleep(2000);
				return;
			}

			// Clears inputs for the next round
			cin.clear();
			cin.ignore(1000, '\n');
			playerOneTurn = true;
		}
	}
}

bool myClass::checkBoard(int row, int column, char userToken)
{
	bool ablePlace;

	if (gameBoard[row][column] == '-')
	{
		ablePlace = true;
	}
	else
	{
		ablePlace = false;
	}
	return(ablePlace);
}

bool myClass::winCheck(char userToken)
{
	bool userWon;

	// Checks for wins on the horizontal
	if (	(gameBoard[0][0] == userToken && gameBoard[0][1] == userToken && gameBoard[0][2] == userToken)
		||	(gameBoard[1][0] == userToken && gameBoard[1][1] == userToken && gameBoard[1][2] == userToken)
		||	(gameBoard[2][0] == userToken && gameBoard[2][1] == userToken && gameBoard[2][2] == userToken))
	{
		userWon = true;
	}

	// Checks for wins on the vertical
	else if (	(gameBoard[0][0] == userToken && gameBoard[1][0] == userToken && gameBoard[2][0] == userToken)
		||		(gameBoard[0][1] == userToken && gameBoard[1][1] == userToken && gameBoard[2][1] == userToken)
		||		(gameBoard[0][2] == userToken && gameBoard[1][2] == userToken && gameBoard[2][2] == userToken))
	{
		userWon = true;
	}

	// Checks for Wins on the diagonal
	else if (	(gameBoard[0][0] == userToken && gameBoard[1][1] == userToken && gameBoard[2][2] == userToken)
		||		(gameBoard[2][0] == userToken && gameBoard[1][1] == userToken && gameBoard[0][2] == userToken))
	{
		userWon = true;
	}
	else
	{
		userWon = false;
	}

	return (userWon);
}

void myClass::placeOnBoard(char userToken, int row, int column)
{
	gameBoard[row][column] = userToken;
}

bool myClass::drawCheck()
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (gameBoard[i][j] == '-')
			{
				return(true);
			}
		}
	}
	return(false);
}

Vector2D myClass::hardAIRowCol(int position)
{

	Vector2D RowCol;
	int countUp = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (gameBoard[i][j] == '-')
			{
				countUp++;
				if (countUp == position)
				{
					RowCol.x = i;
					RowCol.y = j;
				}
			}
		}
	}
	return(RowCol);
}
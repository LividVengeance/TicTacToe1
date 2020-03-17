#include "CMinMax.h"

CMinMax::CMinMax(char gameBoard[3][3], char userToken)
{
	char newGameBoard[3][3];

	if (winCheck(gameBoard, userToken)) // Checks to see if computer won
	{
		heuristic = 1;
	}
	else if (drawCheck(gameBoard)) // Checks to see if game is a draw
	{
		heuristic = 0;
	}
	else if (winCheck(gameBoard, 'X')) // Checks to see if the computer loses
	{
		heuristic = -1;
	}
	else
	{
		// Gens all the posable moves given gameBoard
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (gameBoard[i][j] == '-')
				{
					createNewBoard(gameBoard, newGameBoard);
					newGameBoard[i][j] = userToken;
					CMinMax* newNode = new CMinMax(newGameBoard, userToken);

					vecGameBoards.push_back(newNode);
				}
			}
		}

		// Add up all child heristicks
		// Based on min max thing
	}

	
}

CMinMax::~CMinMax()
{
}

void CMinMax::createNewBoard(char gameBoard[3][3], char newGameBoard[3][3])
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			newGameBoard[i][j] = gameBoard[i][j];
		}
	}
}

bool CMinMax::winCheck(char gameBoard[3][3], char userToken)
{
	bool userWon;

	// Checks for wins on the horizontal
	if ((gameBoard[0][0] == userToken && gameBoard[0][1] == userToken && gameBoard[0][2] == userToken)
		|| (gameBoard[1][0] == userToken && gameBoard[1][1] == userToken && gameBoard[1][2] == userToken)
		|| (gameBoard[2][0] == userToken && gameBoard[2][1] == userToken && gameBoard[2][2] == userToken))
	{
		userWon = true;
	}

	// Checks for wins on the vertical
	else if ((gameBoard[0][0] == userToken && gameBoard[1][0] == userToken && gameBoard[2][0] == userToken)
		|| (gameBoard[0][1] == userToken && gameBoard[1][1] == userToken && gameBoard[2][1] == userToken)
		|| (gameBoard[0][2] == userToken && gameBoard[1][2] == userToken && gameBoard[2][2] == userToken))
	{
		userWon = true;
	}

	// Checks for Wins on the diagonal
	else if ((gameBoard[0][0] == userToken && gameBoard[1][1] == userToken && gameBoard[2][2] == userToken)
		|| (gameBoard[2][0] == userToken && gameBoard[1][1] == userToken && gameBoard[0][2] == userToken))
	{
		userWon = true;
	}
	else
	{
		userWon = false;
	}

	return (userWon);
}

bool CMinMax::drawCheck(char gameBoard[3][3])
{
	bool isDraw;

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
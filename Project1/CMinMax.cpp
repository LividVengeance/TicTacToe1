#include "CMinMax.h"

CMinMax::CMinMax(char gameBoard[3][3])
{
	char newGameBoard[3][3];

	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			newGameBoard[i][j] = gameBoard[i][j];
		}
	}

}

CMinMax::~CMinMax()
{

}

void CMinMax::GenNodes(char gameBoard[3][3], char userToken)
{
	// Gens all the posable moves given gameBoard
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (gameBoard[i][j] == '-')
			{
				gameBoard[i][j] = userToken;
				CMinMax* newNode = new CMinMax(gameBoard);

				vec.push_back(newNode);
			}
		}
	}

	
}
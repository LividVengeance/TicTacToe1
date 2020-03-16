#include "CMinMax.h"

CMinMax::CMinMax(char gameboard[3][3], char userToken)
{

}

CMinMax::~CMinMax()
{

}

void CMinMax::GenChildNodes(char gameboard[3][3], char userToken)
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (gameboard[i][j] == '-')
			{
				CMinMax* newNode = new CMinMax(gameboard[i][j], userToken);

				
			}
		}
	}

	
}
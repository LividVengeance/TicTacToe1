#pragma once

#include <vector>
#include "myClass.h"

using namespace std;

class CMinMax
{
public:
	CMinMax(char gameBoard[3][3], char userToken);
	~CMinMax();

	int GetHeuristic();


	void createNewBoard(char gameBoard[3][3], char newGameBoard[3][3]);

	bool winCheck(char gameBoard[3][3], char userToken);
	bool drawCheck(char gameBoard[3][3]);

	int GetBestMove();

	
	char newGameBoard[3][3];
	vector<CMinMax*> vecGameBoards;
private:
	int heuristic;
	char MyMove;
};



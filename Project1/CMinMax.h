#pragma once

#include <vector>

using namespace std;

class CMinMax
{
public:
	CMinMax(char gameBoard[3][3]);
	~CMinMax();

	void GenNodes(char gameboard[3][3], char userToken);

	vector<CMinMax*> vec;
private:

};



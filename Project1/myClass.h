#pragma once
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class myClass
{
public:
	myClass();
	~myClass();

	char gameBoard[3][3];

	void PrintBoard();
	void playVSEasy();
	void playVSHard();
	void playVSPlay(bool playerOneTurn = true);
	bool checkBoard(int row, int column, char userToken);
	bool winCheck(char userToken);
	void placeOnBoard(char userToken, int row, int column);
	bool drawCheck();
};


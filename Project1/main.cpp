#include <iostream>
#include <windows.h>
#include <cstdlib>

#include "myClass.h"

using namespace std;

void playMenu()
{
	myClass objClass;

	system("CLS");

	cout << endl;
	cout << "	,--,--'    ,--,--'      ,--,--'      " << endl;
	cout << "	`- | . ,-. `- | ,-. ,-. `- | ,-. ,-. " << endl;
	cout << "	 , | | |    , | ,-| |    , | | | |-' " << endl;
	cout << "	 `-' ' `-'  `-' `-^ `-'  `-' `-' `-' " << endl;
	cout << endl << endl;
	cout << "		1. Easy" << endl;
	cout << endl;
	cout << "		2. Hard" << endl;
	cout << endl;
	cout << "		3. Player Vs Player" << endl;
	cout << endl;
	cout << "		4. Back to Main Menu" << endl;
	cout << endl;

	int Option;
	cin >> Option;

	if (Option == 1)
	{
		objClass.playVSEasy();
	}
	else if (Option == 2)
	{
		objClass.playVSHard();
	}
	else if (Option == 3)
	{
		objClass.playVSPlay();
	}
	else if (Option == 4)
	{
		return;
	}
	objClass.PrintBoard();
}

void mainMenu()
{
	system("CLS");

	cout << endl;
	cout << "	,--,--'    ,--,--'      ,--,--'      " << endl;
	cout << "	`- | . ,-. `- | ,-. ,-. `- | ,-. ,-. " << endl;
	cout << "	 , | | |    , | ,-| |    , | | | |-' " << endl;
	cout << "	 `-' ' `-'  `-' `-^ `-'  `-' `-' `-' " << endl;
	cout << endl << endl;
	cout << "		1. Play" << endl;
	cout << endl;
	cout << "		2. Quit" << endl;
	cout << endl;

	int Option;
	cin >> Option;

	if (Option == 1)
	{
		playMenu();
	}
	else if (Option == 2)
	{
		exit(0);
	}
	else
	{
		// If invaild input by user
		system("CLS");
		cout << endl << endl << "		Please Enter A Vaild Input" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		Sleep(1000);
		mainMenu();
	}
}

int main()
{
	// Allows the menus to go back to each other
	while (true)
	{
		mainMenu();
	}
	return(0);
}
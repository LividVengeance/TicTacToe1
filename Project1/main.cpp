#include <iostream>
#include <windows.h>

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

	}
	else if (Option == 3)
	{
		objClass.playVSPlay();
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
		system("exit");
	}
	else
	{
		system("CLS");
		cout << endl << endl << "Please Enter A Vaild Input" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		Sleep(1000);
		mainMenu();
	}
}

int main()
{
	mainMenu();
	return(0);
}
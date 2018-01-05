#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	HANDLE hConsole;
	int k;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// you can loop k higher to see more color choices
	for (k = 0; k < 16; k++) {
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, k);
		cout << k << " I want to be nice today!" << endl;
	}

	SetConsoleTextAttribute(hConsole, 15);
	return 0;
}

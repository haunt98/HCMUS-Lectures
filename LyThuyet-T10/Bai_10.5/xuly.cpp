#include "xuly.h"

int **createBuilding(int Floor, int Room)
{
	int **Building = new int*[Floor];
	for (int i = 0; i < Floor; i++)
	{
		Building[i] = new int[Room];
	}
	for (int i = 0; i < Floor; i++)
	{
		for (int j = 0; j < Room; j++)
			Building[i][j] = i*j + 1;
	}
	return Building;
}

void showBuilding(int **Building, int Floor, int Room)
{
	for (int i = 0; i < Floor; i++)
	{
		for (int j = 0; j < Room; j++)
		{
			cout << Building[i][j] << " ";
		}
		cout << endl;
	}
}
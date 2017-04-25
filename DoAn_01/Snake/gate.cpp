#include "xuly.h"

POINT my_gate[SIZE_GATE];
int STATE;
int GATE_STATE = 0;

void CreateGate()
{
	// XXX
	// X X
	srand(time(NULL));
	do{
		my_gate[0].x = rand() % (WIDTH_CONSOLE - 1) + 1;
		my_gate[0].y = rand() % (HEIGHT_CONSOLE - 1) + 1;
		my_gate[1] = { my_gate[0].x, my_gate[0].y - 1 };
		my_gate[2] = { my_gate[0].x + 1, my_gate[0].y - 1 };
		my_gate[3] = { my_gate[0].x + 2, my_gate[0].y - 1 };
		my_gate[4] = { my_gate[0].x + 2, my_gate[0].y };
	} while (!CheckGate());
	GATE_STATE = 1;
}

bool CheckGate()
{
	for (int i = 0; i < SIZE_GATE; ++i)
	{
		if (!IsValid(my_gate[i].x, my_gate[i].y))
			return false;
	}
	for (int i = 0; i < SIZE_GATE; ++i)
	{
		if (my_gate[i].x == food[FOOD_INDEX].x && my_gate[i].y == food[FOOD_INDEX].y)
			return false;
	}
	// Cong khong trung hang rao
	if (my_gate[0].x<4 || my_gate[0].y>WIDTH_CONSOLE - 4)
		return false;
	if (my_gate[0].y<4 || my_gate[0].y>HEIGHT_CONSOLE - 4)
		return false;
	return true;
}

void DrawGate()
{
	if (GATE_STATE)
	{
		for (int i = 0; i < SIZE_GATE; ++i)
		{
			GotoXY(my_gate[i].x, my_gate[i].y);
			cout << "X";
		}
	}
}

void CloseGate()
{
	for (int i = 0; i < SIZE_GATE; ++i)
	{
		GotoXY(my_gate[i].x, my_gate[i].y);
		cout << " ";
	}
	GATE_STATE = 0;
}
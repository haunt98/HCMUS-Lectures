#include "xuly.h"

POINT my_gate[SIZE_GATE];
bool STATE;
bool GATE_STATE = false;

void DrawGate()
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
	} while (!IsValid(my_gate[0].x, my_gate[0].y) ||
		!IsValid(my_gate[1].x, my_gate[1].y) ||
		!IsValid(my_gate[2].x, my_gate[2].y) ||
		!IsValid(my_gate[3].x, my_gate[3].y) ||
		!IsValid(my_gate[4].x, my_gate[4].y) ||
		(my_gate[0].x == food[FOOD_INDEX].x &&
		my_gate[0].y == food[FOOD_INDEX].y) ||
		(my_gate[1].x == food[FOOD_INDEX].x &&
		my_gate[1].y == food[FOOD_INDEX].y) ||
		(my_gate[2].x == food[FOOD_INDEX].x &&
		my_gate[2].y == food[FOOD_INDEX].y) ||
		(my_gate[3].x == food[FOOD_INDEX].x &&
		my_gate[3].y == food[FOOD_INDEX].y) ||
		(my_gate[4].x == food[FOOD_INDEX].x &&
		my_gate[4].y == food[FOOD_INDEX].y) ||
		my_gate[0].y == HEIGHT_CONSOLE - 1 ||
		my_gate[0].x == WIDTH_CONSOLE - 2);
	// draw
	for (int i = 0; i < SIZE_GATE; ++i)
	{
		GotoXY(my_gate[i].x, my_gate[i].y);
		cout << "X";
	}
	GATE_STATE = true;
}

void CloseGate()
{
	for (int i = 0; i < SIZE_GATE; ++i)
	{
		GotoXY(my_gate[i].x, my_gate[i].y);
		cout << " ";
	}
	GATE_STATE = false;
}
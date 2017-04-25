#include "xuly.h"

bool TouchRightBody()
{
	for (int i = 0; i < SIZE_SNAKE - 1; ++i)
	{
		if (snake[i].x == snake[SIZE_SNAKE - 1].x + 1 &&
			snake[i].y == snake[SIZE_SNAKE - 1].y)
			return true;
	}
	return false;
}
bool TouchLeftBody()
{
	for (int i = 0; i < SIZE_SNAKE - 1; ++i)
	{
		if (snake[i].x == snake[SIZE_SNAKE - 1].x - 1 &&
			snake[i].y == snake[SIZE_SNAKE - 1].y)
			return true;
	}
	return false;
}
bool TouchDownBody()
{
	for (int i = 0; i < SIZE_SNAKE - 1; ++i)
	{
		if (snake[i].x == snake[SIZE_SNAKE - 1].x &&
			snake[i].y == snake[SIZE_SNAKE - 1].y + 1)
			return true;
	}
	return false;
}
bool TouchUpBody()
{
	for (int i = 0; i < SIZE_SNAKE - 1; ++i)
	{
		if (snake[i].x == snake[SIZE_SNAKE - 1].x &&
			snake[i].y == snake[SIZE_SNAKE - 1].y - 1)
			return true;
	}
	return false;
}

bool TouchRightGate()
{
	//XXX
	//X X
	if (GATE_STATE)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (my_gate[i].x == snake[SIZE_SNAKE - 1].x + 1 &&
				my_gate[i].y == snake[SIZE_SNAKE - 1].y)
				return true;
		}
	}
	return false;
}
bool TouchLeftGate()
{
	//XXX
	//X X
	if (GATE_STATE)
	{
		for (int i = 3; i < SIZE_GATE; ++i)
		{
			if (my_gate[i].x == snake[SIZE_SNAKE - 1].x - 1 &&
				my_gate[i].y == snake[SIZE_SNAKE - 1].y)
				return true;
		}
	}
	return false;
}
bool TouchUpGate()
{
	//XXX
	//X X
	if (GATE_STATE)
	{
		for (int i = 0; i < SIZE_GATE; ++i)
		{
			if (i == 0 || i == 4)
			{
				if (my_gate[i].x == snake[SIZE_SNAKE - 1].x &&
					my_gate[i].y == snake[SIZE_SNAKE - 1].y - 1)
					return true;
			}
		}
	}
	return false;
}
bool TouchDownGate()
{
	//XXX
	//X X
	if (GATE_STATE)
	{
		for (int i = 1; i < SIZE_GATE - 1; ++i)
		{
			if (my_gate[i].x == snake[SIZE_SNAKE - 1].x &&
				my_gate[i].y == snake[SIZE_SNAKE - 1].y + 1)
				return true;
		}
	}
	return false;
}

void ProcessDead()
{
	STATE = 0;
	GotoXY(0, HEIGHT_CONSOLE + 2);
	cout << "Dead, type y to continue or anykey to exit" << endl;
}
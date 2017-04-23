#include "xuly.h"

void MoveRight()
{
	if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE ||
		TouchRightBody() || TouchRightGate())
		ProcessDead();
	else
	{
		if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x &&
			snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
			Eat();
		// move
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x++;
	}
}

void MoveLeft() {
	if (snake[SIZE_SNAKE - 1].x - 1 == 0 ||
		TouchLeftBody() || TouchLeftGate())
		ProcessDead();
	else {
		if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_INDEX].x &&
			snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
			Eat();
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;

			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].x--;
	}
}

void MoveDown()
{
	if (snake[SIZE_SNAKE - 1].y + 1 == HEIGHT_CONSOLE ||
		TouchDownBody() || TouchDownGate())
		ProcessDead();
	else
	{
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x &&
			snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_INDEX].y)
			Eat();
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y++;
	}
}

void MoveUp()
{
	if (snake[SIZE_SNAKE - 1].y - 1 == 0 ||
		TouchUpBody() || TouchUpGate())
		ProcessDead();

	else if (snake[SIZE_SNAKE - 1].y - 1 == my_gate[2].y &&
		snake[SIZE_SNAKE - 1].x == my_gate[2].x)
	{
		GotoXY(snake[SIZE_SNAKE - 1].x, snake[SIZE_SNAKE - 1].y);
		cout << " ";

		if (TEMP_SNAKE < SIZE_SNAKE)
			TEMP_SNAKE = SIZE_SNAKE;
		if (SIZE_SNAKE > 0)
		{
			SIZE_SNAKE--;
			MoveUp();
		}
		if (SIZE_SNAKE == 0)
		{
			CloseGate();
			CHAR_LOCK = 'A', MOVING = 'D', SPEED = SPEED += 2;
			FOOD_INDEX = 0, SIZE_SNAKE = TEMP_SNAKE;
			for (int i = 0; i < SIZE_SNAKE; ++i)
			{
				snake[i] = { 10 + i, 5 };
			}
			GenerateFood();
		}
	}

	else
	{
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x &&
			snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y)
		{
			Eat();
			GenerateFood();
		}
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y--;
	}
}

void Eat()
{
	snake[SIZE_SNAKE] = food[FOOD_INDEX];
	if (FOOD_INDEX == MAX_SIZE_FOOD - 1)
	{
		FOOD_INDEX = 0;
		// max level
		if (SPEED == MAX_SPEED)
		{
			SIZE_SNAKE = LOW_SIZE_SNAKE;
			SPEED = LOW_SPEED;
			GenerateFood();
		}
		// level up
		else
		{
			if (!GATE_STATE)
			{
				DrawGate();
				SIZE_SNAKE++;
			}
		}
	}
	else
	{
		FOOD_INDEX++;
		SIZE_SNAKE++;
	}
}
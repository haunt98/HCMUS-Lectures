#include "xuly.h"

void DrawBoard(int x, int y, int width, int height,
	int curPosX, int curPosY)
{
	// ngang
	GotoXY(x, y);
	for (int i = 0; i <= width; i++)
		cout << '#';
	GotoXY(x, height + y);
	for (int i = 0; i <= width; i++)
		cout << '#';
	// doc
	for (int i = y + 1; i < height + y; i++)
	{
		GotoXY(x, i); cout << '#';
		GotoXY(x + width, i); cout << '#';
	}
	GotoXY(curPosX, curPosY);
}

void DrawSnakeAndFood(char* draw_snake, char *draw_food)
{
	if (!GATE_STATE)
	{
		GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
		cout << draw_food;
	}
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GotoXY(snake[i].x, snake[i].y);
		cout << draw_snake;
	}
	GotoXY(WIDTH_CONSOLE + 1, 2);
	cout << " SPEED : " << SPEED;
	//cout << SIZE_SNAKE;
}
#include "xuly.h"

void DrawBoard(int x, int y, int width, int height, int curPosX, int curPosY)
{
	// ngang
	GotoXY(x, y);
	for (int i = 0; i <= width; i++)
		cout << '#';
	GotoXY(x, height + y);
	for (int i = 0; i <= width; i++)
		cout << '#';
	// doc
	for (int i = y + 1; i < height + y; i++) {
		GotoXY(x, i);
		cout << '#';
		GotoXY(x + width, i);
		cout << '#';
	}
	GotoXY(curPosX, curPosY);
}

void DrawSnakeFoodGate(char char_snake, char char_food)
{
	DrawFood(char_food);
	DrawSnake(char_snake);
	DrawGate();
}

void DrawFood(char char_food)
{
	if (!GATE_STATE) {
		GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
		cout << char_food;
	}
}

void DrawSnake(char char_snake)
{
	if (char_snake == ' ') {
		for (int i = 0; i < SIZE_SNAKE; i++) {
			GotoXY(snake[i].x, snake[i].y);
			cout << char_snake;
		}
	} else {
		for (int i = 0; i < SIZE_SNAKE; i++) {
			GotoXY(snake[i].x, snake[i].y);
			cout << MSSV[i % 7];
		}
	}
}

void DrawSpeed()
{
	GotoXY(WIDTH_CONSOLE + 1, 2);
	cout << " SPEED : " << SPEED;
	// GotoXY(WIDTH_CONSOLE + 1, 3);
	// cout << " GATE : " << GATE_STATE;
}
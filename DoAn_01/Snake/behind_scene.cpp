#include "xuly.h"

int HEIGHT_CONSOLE = 20, WIDTH_CONSOLE = 60;
int CHAR_LOCK, MOVING, SPEED;
POINT snake[MAX_SIZE_SNAKE];
POINT food[MAX_SIZE_FOOD];
int SIZE_SNAKE, FOOD_INDEX;
int TEMP_SNAKE = 0;
char MSSV[8] = "1612180";

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y)
{
	COORD cursor_pos = { x, y };
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, cursor_pos);
}

// An con tro nhap nhay
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

bool IsValid(int x, int y)
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == x && snake[i].y == y)
			return false;
	}
	return true;
}
void GenerateFood()
{
	int x, y;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD; i++)
	{
		do {
			x = rand() % (WIDTH_CONSOLE - 1) + 1;
			y = rand() % (HEIGHT_CONSOLE - 1) + 1;
		} while (!IsValid(x, y) ||
			x <2 || x > WIDTH_CONSOLE - 2 ||
			y < 2 || y > HEIGHT_CONSOLE - 2);
		food[i] = { x, y };
	}
}
// Initial STATS
void ResetData()
{
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = LOW_SPEED;
	FOOD_INDEX = 0, SIZE_SNAKE = LOW_SIZE_SNAKE;
	for (int i = 0; i < SIZE_SNAKE; ++i)
	{
		snake[i] = { 10 + i, 5 };
	}
	GenerateFood();
}

void StartGame()
{
	system("cls");
	CloseGate();
	ResetData();
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGHT_CONSOLE);
	STATE = 1;
}
void ExitGame(HANDLE t)
{
	system("cls");
	TerminateThread(t, 0);
	exit(0);
}

void ThreadFunc()
{
	while (true)
	{
		if (STATE)
		{
			DrawSnakeFoodGate(' ', ' ');
			switch (MOVING)
			{
			case 'A':
				MoveLeft();
				break;
			case 'D':
				MoveRight();
				break;
			case 'W':
				MoveUp();
				break;
			case 'S':
				MoveDown();
				break;
			}
			DrawSnakeFoodGate('O', 'F');
			DrawSpeed();
			Sleep(1000 / SPEED);
		}
	}
}
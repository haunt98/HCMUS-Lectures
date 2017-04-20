#include "xuly.h"

int HEIGHT_CONSOLE, WIDTH_CONSOLE;
int CHAR_LOCK, MOVING, SPEED;
POINT snake[MAX_SIZE_SNAKE];
POINT food[MAX_SIZE_FOOD];
POINT my_gate[SIZE_GATE];
int SIZE_SNAKE, FOOD_INDEX;
bool STATE;

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
	if (x == 0 || x == WIDTH_CONSOLE ||
		y == 0 || y == HEIGHT_CONSOLE)
		return false;
	return true;
}
void GenerateFood()
{
	int x, y;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE_FOOD; i++) {
		do {
			x = rand() % (WIDTH_CONSOLE - 1) + 1;
			y = rand() % (HEIGHT_CONSOLE - 1) + 1;
		} while (IsValid(x, y) == false);
		food[i] = { x, y };
	}
}
void ResetData()
{
	CHAR_LOCK = 'A', MOVING = 'D', SPEED = 10;
	FOOD_INDEX = 0, WIDTH_CONSOLE = 80, HEIGHT_CONSOLE = 20, SIZE_SNAKE = 6;
	snake[0] = { 10, 5 }; snake[1] = { 11, 5 };
	snake[2] = { 12, 5 }; snake[3] = { 13, 5 };
	snake[4] = { 14, 5 }; snake[5] = { 15, 5 };
	GenerateFood();
}

void StartGame()
{
	system("cls");
	ResetData();
	DrawBoard(0, 0, WIDTH_CONSOLE, HEIGHT_CONSOLE);
	STATE = true;
}
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

void ProcessDead()
{
	STATE = false;
	GotoXY(0, HEIGHT_CONSOLE + 2);
	cout << "Dead, type y to continue or anykey to exit" << endl;
}
void ExitGame(HANDLE t)
{
	system("cls");
	TerminateThread(t, 0);
}
void PauseGame(HANDLE t)
{
	SuspendThread(t);
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
			SIZE_SNAKE = 6;
			SPEED = 1;
		}
		// level up
		else
		{
			DrawGate();
			SPEED++;
			//CloseGate();
		}
		GenerateFood();
	}
	else
	{
		FOOD_INDEX++;
		SIZE_SNAKE++;
	}
}

bool isTouchBody()
{
	for (int i = 0; i < SIZE_SNAKE - 1; ++i)
	{
		if (snake[i].x == snake[SIZE_SNAKE - 1].x &&
			snake[i].y == snake[SIZE_SNAKE - 1].y)
			return true;
	}
	return false;
}
void MoveRight()
{
	if (snake[SIZE_SNAKE - 1].x + 1 == WIDTH_CONSOLE || isTouchBody())
		ProcessDead();
	else {
		if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_INDEX].x &&
			snake[SIZE_SNAKE - 1].y == food[FOOD_INDEX].y)
			Eat();

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
		isTouchBody())
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
		isTouchBody())
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
		isTouchBody())
		ProcessDead();
	else
	{
		if (snake[SIZE_SNAKE - 1].x == food[FOOD_INDEX].x &&
			snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_INDEX].y)
			Eat();
		for (int i = 0; i < SIZE_SNAKE - 1; i++)
		{
			snake[i].x = snake[i + 1].x;
			snake[i].y = snake[i + 1].y;
		}
		snake[SIZE_SNAKE - 1].y--;
	}
}

void DrawSnakeAndFood(char* draw_snake, char *draw_food)
{
	GotoXY(food[FOOD_INDEX].x, food[FOOD_INDEX].y);
	cout << draw_food;
	for (int i = 0; i < SIZE_SNAKE; i++){
		GotoXY(snake[i].x, snake[i].y);
		cout << draw_snake;
	}
}
void ThreadFunc()
{
	while (true)
	{
		if (STATE)
		{
			DrawSnakeAndFood(" ", " ");
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
			DrawSnakeAndFood("O", "F");
			Sleep(1000 / SPEED);
		}
	}
}

void SaveGame(char *filename)
{
	FILE *f = fopen(filename, "w");
	fprintf(f, "%d %d\n", SIZE_SNAKE, FOOD_INDEX);
	fprintf(f, "%d %d %d\n", CHAR_LOCK, MOVING, SPEED);
	for (int i = 0; i < SIZE_SNAKE; ++i)
	{
		fprintf(f, "%d %d ", snake[i].x, snake[i].y);
	}
	fprintf(f, "\n");
	for (int i = 0; i < FOOD_INDEX; ++i)
	{
		fprintf(f, "%d %d ", food[i].x, food[i].y);
	}
}
void LoadGame(char *filename)
{
	FILE *f = fopen(filename, "r");
	fscanf(f, "%d %d", &SIZE_SNAKE, &FOOD_INDEX);
	fscanf(f, "%d %d %d", &CHAR_LOCK, &MOVING, &SPEED);
	for (int i = 0; i < SIZE_SNAKE; ++i)
	{
		fscanf(f, "%d %d", &snake[i].x, &snake[i].y);
	}
	for (int i = 0; i < FOOD_INDEX; ++i)
	{
		fscanf(f, "%d %d", &food[i].x, &food[i].y);
	}
}

void DrawGate()
{
	// XXX
	// X X

	do{
		my_gate[0].x = rand() % (WIDTH_CONSOLE - 1) + 1;
		my_gate[0].y = rand() % (HEIGHT_CONSOLE - 1) + 1;
		my_gate[1] = { my_gate[0].x, my_gate[0].y - 1 };
		my_gate[2] = { my_gate[0].x + 1, my_gate[0].y - 1 };
		my_gate[3] = { my_gate[0].x + 2, my_gate[0].y - 1 };
		my_gate[4] = { my_gate[0].x + 2, my_gate[0].y };
	} while (IsValid(my_gate[0].x, my_gate[0].y) &&
		IsValid(my_gate[1].x, my_gate[1].y) &&
		IsValid(my_gate[2].x, my_gate[2].y) &&
		IsValid(my_gate[3].x, my_gate[3].y) &&
		IsValid(my_gate[4].x, my_gate[4].y) &&
		my_gate[0].x != food[FOOD_INDEX].x &&
		my_gate[0].y != food[FOOD_INDEX].y &&
		my_gate[1].x != food[FOOD_INDEX].x &&
		my_gate[1].y != food[FOOD_INDEX].y &&
		my_gate[2].x != food[FOOD_INDEX].x &&
		my_gate[2].y != food[FOOD_INDEX].y &&
		my_gate[3].x != food[FOOD_INDEX].x &&
		my_gate[3].y != food[FOOD_INDEX].y &&
		my_gate[4].x != food[FOOD_INDEX].x &&
		my_gate[5].y != food[FOOD_INDEX].y);
	// draw
	for (int i = 0; i < SIZE_GATE; ++i)
	{
		GotoXY(my_gate[i].x, my_gate[i].y);
		cout << "X";
	}
}
void CloseGate()
{
	for (int i = 0; i < SIZE_GATE; ++i)
	{
		GotoXY(my_gate[i].x, my_gate[i].y);
		cout << " ";
	}
}
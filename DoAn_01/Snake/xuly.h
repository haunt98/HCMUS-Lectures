#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <conio.h>
using namespace std;

#define MAX_SIZE_SNAKE 10
#define MAX_SIZE_FOOD 4
#define MAX_SPEED 3
#define ESC 27

extern int CHAR_LOCK;
extern int MOVING;
extern int SPEED;
extern int HEIGH_CONSOLE, WIDTH_CONSOLE;
extern int FOOD_INDEX;
extern int SIZE_SNAKE;
extern int STATE;

void FixConsoleWindow();
void GotoXY(int x, int y);
bool IsValid(int x, int y);
void GenerateFood();
void ResetData();
void StartGame();
void DrawBoard(int x, int y, int width, int height,
	int curPosX = 0, int curPosY = 0);
void ExitGame(HANDLE t);
void PauseGame(HANDLE t);
void Eat();
void ProcessDead();
void DrawSnakeAndFood(char* str);
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void ThreadFunc();

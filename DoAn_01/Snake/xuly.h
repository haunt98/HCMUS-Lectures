#ifndef XULY_H
#define XULY_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <conio.h>
using namespace std;

#define MAX_SIZE_SNAKE 20
#define MAX_SIZE_FOOD 2
#define MAX_SPEED 20
#define SIZE_GATE 5
#define ESC 27
#define DEBUG 0

extern int HEIGHT_CONSOLE, WIDTH_CONSOLE;
extern int CHAR_LOCK, MOVING, SPEED;
extern POINT snake[MAX_SIZE_SNAKE];
extern POINT food[MAX_SIZE_FOOD];
extern POINT my_gate[SIZE_GATE];
extern int FOOD_INDEX, SIZE_SNAKE;
extern bool STATE;

void FixConsoleWindow();
void GotoXY(int x, int y);
void ShowCur(bool CursorVisibility);

bool IsValid(int x, int y);
void GenerateFood();
void ResetData();

void StartGame();
void DrawBoard(int x, int y, int width, int height,
	int curPosX = 0, int curPosY = 0);
void ProcessDead();
void ExitGame(HANDLE t);
void PauseGame(HANDLE t);

void Eat();
bool isTouchBody();
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
void DrawSnakeAndFood(char* draw_snake, char *draw_food);
void ThreadFunc();

void SaveGame(char *filename);
void LoadGame(char *filename);

void DrawGate();
void CloseGate();
void PassGate();
#endif

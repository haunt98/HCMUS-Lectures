#ifndef XULY_H
#define XULY_H
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <thread>
#include <time.h>
using namespace std;

#define MAX_SIZE_SNAKE 100
#define MAX_SIZE_FOOD 4
#define MAX_SPEED 20
#define SIZE_GATE 5
#define ESC 27
#define DEBUG 0

#define LOW_SPEED 10
#define LOW_SIZE_SNAKE 7 // 1612180

extern int HEIGHT_CONSOLE, WIDTH_CONSOLE;
extern int CHAR_LOCK, MOVING, SPEED;
extern POINT snake[MAX_SIZE_SNAKE];
extern POINT food[MAX_SIZE_FOOD];
extern POINT my_gate[SIZE_GATE];
extern int FOOD_INDEX, SIZE_SNAKE;
extern int TEMP_SNAKE;
extern int STATE;
extern int GATE_STATE;
extern char MSSV[8];

void FixConsoleWindow();
void GotoXY(int x, int y);
void ShowCur(bool CursorVisibility);

bool IsValid(int x, int y);
void GenerateFood();
void ResetData();

void StartGame();
void DrawBoard(int x, int y, int width, int height, int curPosX = 0,
	       int curPosY = 0);
void ProcessDead();
void ExitGame(HANDLE t);

void Eat();

bool TouchRightBody();
bool TouchLeftBody();
bool TouchDownBody();
bool TouchUpBody();

bool TouchRightGate();
bool TouchLeftGate();
bool TouchDownGate();
bool TouchUpGate();

void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();

void DrawSnakeFoodGate(char char_snake, char char_food);
void DrawFood(char char_food);
void DrawSnake(char char_snake);
void DrawSpeed();
void ThreadFunc();

void SaveGame(char *filename);
void LoadGame(char *filename);

void CreateGate();
bool CheckGate();
void DrawGate();
void CloseGate();
void PassGate();
#endif

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define NUMB 8
#define AVAIL 1
#define UNAVAIL 0
using namespace std;

void printBoard(int chess[NUMB][NUMB]);

bool checkBoard(int row, int col, int chess[NUMB][NUMB]);

bool fullBoard(int chess[NUMB][NUMB]);

void tryQueen(int col, int chess[NUMB][NUMB]);

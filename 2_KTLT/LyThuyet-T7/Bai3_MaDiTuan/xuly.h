#include <iomanip>
#include <iostream>
using namespace std;
#define NUMB 8
#define NOTPASS 0
#define MAX_MOVE 8  // Con ma di chuyen duoc 8 o xung quanh
#define MAX_SPACE 3 // Khoang cach giua cac o
extern int row_move[MAX_MOVE];
extern int col_move[MAX_MOVE];

bool checkMove(int row, int col, int chess[NUMB][NUMB]);

void printBoard(int chess[NUMB][NUMB]);

void tryKnight(int row, int col, int chess[NUMB][NUMB], int step);
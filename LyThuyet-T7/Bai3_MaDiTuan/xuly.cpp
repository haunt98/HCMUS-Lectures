#include "xuly.h"

int row_move[MAX_MOVE] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int col_move[MAX_MOVE] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool checkMove(int row, int col, int chess[NUMB][NUMB])
{
	if (row < 0 || row >= NUMB)
		return false;
	if (col < 0 || col >= NUMB)
		return false;
	if (chess[row][col] == NOTPASS)
		return true;
	return false;
}

void printBoard(int chess[NUMB][NUMB])
{
	cout << "Solution : " << endl;
	for (int row = 0; row < NUMB; ++row)
	{
		for (int col = 0; col < NUMB; ++col)
		{
			cout << setw(MAX_SPACE) << chess[row][col];
		}
		cout << endl;
	}
}

void tryKnight(int row, int col, int chess[NUMB][NUMB], int step)
{
	if (step == NUMB*NUMB - 1)
	{
		printBoard(chess);
		return;
	}
	for (int i = 0; i < MAX_MOVE; ++i)
	{
		int new_row = row + row_move[i];
		int new_col = col + col_move[i];
		// Kiem tra dat quan ma tiep theo
		if (checkMove(new_row, new_col, chess))
		{
			chess[new_row][new_col] = step + 1;
			tryKnight(new_row, new_col, chess, step + 1);
			// backtrack
			chess[new_row][new_col] = NOTPASS;
		}
	}
}
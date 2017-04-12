#include "xuly.h"

void printBoard(int chess[NUMB][NUMB])
{
	cout << "Solution : " << endl;
	for (int row = 0; row < NUMB; ++row)
	{
		for (int col = 0; col < NUMB; ++col)
		{
			if (chess[row][col] == AVAIL)
				cout << " Q ";
			else
				cout << " - ";
		}
		cout << endl;
	}
}

bool checkBoard(int row, int col, int chess[NUMB][NUMB])
{
	int i, j;
	for (i = 0; i < NUMB; ++i)
	{
		if (chess[row][i] == AVAIL)
			return false;
	}
	for (i = 0; i < NUMB; ++i)
	{
		if (chess[i][col] == AVAIL)
			return false;
	}
	for (i = 0; i < NUMB; ++i)
	{
		for (j = 0; j < NUMB; ++j)
		{
			if (chess[i][j] == AVAIL && abs(i - row) == abs(j - col))
				return false;
		}
	}
	return true;
}

bool fullBoard(int chess[NUMB][NUMB])
{
	int temp = 0;
	for (int row = 0; row < NUMB; ++row)
	{
		for (int col = 0; col < NUMB; ++col)
		{
			if (chess[row][col] == AVAIL)
				++temp;
		}
	}
	if (temp == NUMB)
		return true;
	return false;
}

void tryQueen(int col, int chess[NUMB][NUMB])
{
	if (fullBoard(chess))
	{
		printBoard(chess);
		return;
	}
	for (int i = 0; i < NUMB; ++i)
	{
		// Trong cung mot cot, xu ly tu hang dau tien -> cuoi cung
		if (checkBoard(i, col, chess))
		{
			chess[i][col] = AVAIL;
			// Xu ly cot tiep theo
			tryQueen(col + 1, chess);
			// backtrack
			chess[i][col] = UNAVAIL;
		}
	}
}
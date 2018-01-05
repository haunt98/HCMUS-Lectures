#include "xuly.h"

int main(void)
{
	int chess[NUMB][NUMB];

	for (int row = 0; row < NUMB; ++row) {
		for (int col = 0; col < NUMB; ++col) {
			chess[row][col] = UNAVAIL;
		}
	}
	tryQueen(0, chess);
	return 0;
}
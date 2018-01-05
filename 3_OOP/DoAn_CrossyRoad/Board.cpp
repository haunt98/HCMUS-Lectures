#include "Board.h"
#include "ToaDo.h"

using namespace std;

void DrawBoard()
{
	const int CHAR_BLOCK_UP = 220;
	const int CHAR_BLOCK_DOWN = 223;
	const int CHAR_BLOCK_LEFT = 221;
	const int CHAR_BLOCK_RIGHT = 222;
	for (int i = 0; i < HEIGHT_BOARD; ++i) {
		if (i == 0) {
			for (int j = 0; j < WIDTH_BOARD; ++j) {
				ToaDo(j, i).Draw(CHAR_BLOCK_UP);
			}
		} else if (i == HEIGHT_BOARD - 1) {
			for (int j = 0; j < WIDTH_BOARD; ++j) {
				ToaDo(j, i).Draw(CHAR_BLOCK_DOWN);
			}
		} else {
			ToaDo(0, i).Draw(CHAR_BLOCK_LEFT);
			ToaDo(WIDTH_BOARD - 1, i).Draw(CHAR_BLOCK_RIGHT);
		}
	}
}
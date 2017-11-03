#include "func.h"

int main(void)
{
	char *linkFrom = new char[MAX]; char *linkTo = new char[MAX];
	Pixel PixelFrom, PixelTo;

	inputText("Bitmap.in", linkFrom, linkTo, PixelFrom, PixelTo);

	changeRedtoYellow(linkFrom, linkTo);
	displayBMP(linkFrom);

	outputText("Bitmap.out", linkFrom, linkTo, PixelFrom, PixelTo);
	delete[]linkFrom; delete[]linkTo;
	return 0;
}
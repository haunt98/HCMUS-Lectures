#include "func.h"

bool isBMP(char *filename)
{
	FILE *f = fopen(filename, "rb");
	if (!f)
		return false;
	BitmapHeader Header;
	fread(&Header, sizeof(BitmapHeader), 1, f);
	fclose(f);
	char *p = Header.FileType;
	if (*p == 'B' && *(p + 1) == 'M')
		return true;
	return false;
}

void printInfo(char *filename)
{
	FILE *f = fopen(filename, "rb");
	if (!f)
		return;
	BitmapHeader Header; BitmapDIP DIP;
	fread(&Header, sizeof(BitmapHeader), 1, f);
	fread(&DIP, sizeof(BitmapDIP), 1, f);
	printf("Info of file: %s\n", filename);
	printf("Size of File: %d\n", Header.FileSize);
	printf("Image Width:  %d\n", DIP.ImageWidth);
	printf("Image Height: %d\n", DIP.ImageHeight);
	fclose(f);
}

void copyFile(FILE *input, FILE *output)
{
	if (!input)
		return;
	fseek(input, 0, SEEK_SET);
	char *p = new char[BUFFER]; int count;
	do{
		count = fread(p, sizeof(char), BUFFER, input);
		fwrite(p, sizeof(char), count, output);
	} while (count == BUFFER);
	delete[]p;
}

void readPixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray &Array)
{
	if (!f)
		return;
	fseek(f, Header.BitMapOffset, SEEK_SET);
	// set up array
	Array.row = DIP.ImageHeight;
	Array.column = DIP.ImageWidth;
	// set up padding
	uint32_t i, j, padding = (4 - (DIP.ImageWidth * (DIP.BitsPerPixel / 8) % 4)) % 4;
	uint32_t pad;

	Array.dataArray = new Pixel *[Array.row];
	for (i = 0; i < Array.row; ++i)
	{
		Array.dataArray[Array.row - 1 - i] = new Pixel[Array.column];
		fread(Array.dataArray[Array.row - 1 - i], sizeof(Pixel), Array.column, f);
		// skip padding
		fread(&pad, 1, padding, f);
	}
}

void writePixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray Array)
{
	if (!f)
		return;
	fseek(f, Header.BitMapOffset, SEEK_SET);
	uint32_t i, j, padding = (4 - (DIP.ImageWidth * (DIP.BitsPerPixel / 8) % 4)) % 4;
	uint32_t pad = 0;
	for (i = 0; i < Array.row; ++i)
	{
		fwrite(Array.dataArray[Array.row - 1 - i], sizeof(Pixel), Array.column, f);
		// write padding
		fwrite(&pad, 1, padding, f);
	}
}

void changePixelArray(PixelArray &A)
{
	for (int i = 0; i < A.row; ++i)
		for (int j = 0; j < A.column; ++j)
		{
			Pixel *p = &A.dataArray[i][j];
			if (p->Red == 255 && p->Green == 0 && p->Red == 0)
				p->Blue = 255;
		}
}

void changeRedtoYellow(char *input, char *output)
{
	FILE *in = fopen(input, "rb");
	FILE *out = fopen(output, "wb");
	if (!in)
		return;
	BitmapHeader Header; BitmapDIP DIP; PixelArray Array;
	fread(&Header, sizeof(BitmapHeader), 1, in);
	fread(&DIP, sizeof(BitmapDIP), 1, in);

	readPixelArray(in, Header, DIP, Array);
	changePixelArray(Array); // change color
	copyFile(in, out);
	writePixelArray(out, Header, DIP, Array);

	freePixelArray(Array);
	fclose(in); fclose(out);
}

void freePixelArray(PixelArray &A)
{
	for (int i = 0; i < A.row; ++i)
		delete[]A.dataArray[i];
	delete[]A.dataArray;
}

void displayBMP(char *filename)
{
	FILE *in = fopen(filename, "rb");
	BitmapHeader Header; BitmapDIP DIP; PixelArray Array;

	fread(&Header, sizeof(BitmapHeader), 1, in);
	fread(&DIP, sizeof(BitmapDIP), 1, in);
	readPixelArray(in, Header, DIP, Array);
	HWND console = GetConsoleWindow();
	HDC hdc = GetDC(console);

	uint32_t i, j;
	for (i = 0; i < Array.row; i++)
		for (j = 0; j < Array.column; j++)
		{
			Pixel P = Array.dataArray[i][j];
			SetPixel(hdc, j, i, RGB(P.Red, P.Green, P.Blue));
		}
	ReleaseDC(console, hdc);
}

void inputText(char *filename, char *linkFrom, char *linkTo, Pixel &PixelFrom, Pixel &PixelTo)
{
	FILE *f = fopen(filename, "r");
	if (!f)
		return;
	fgets(linkFrom, MAX, f);
	linkFrom[strlen(linkFrom) - 1] = '\0';
	fgets(linkTo, MAX, f);
	linkTo[strlen(linkTo) - 1] = '\0';
	fscanf(f, "%hhu" "%hhu" "%hhu", &PixelFrom.Red, &PixelFrom.Green, &PixelFrom.Blue);
	fscanf(f, "%hhu" "%hhu"  "%hhu", &PixelTo.Red, &PixelTo.Green, &PixelTo.Blue);
}

void outputText(char *filename, char *linkFrom, char *linkTo, Pixel PixelFrom, Pixel PixelTo)
{
	FILE *f = fopen(filename, "w");
	fprintf(f, "%d\n", isBMP(linkFrom));

	FILE *f_from = fopen(linkFrom, "rb");
	if (!f_from)
		return;
	BitmapHeader Header; BitmapDIP DIP;
	fread(&Header, sizeof(BitmapHeader), 1, f_from);
	fread(&DIP, sizeof(BitmapDIP), 1, f_from);
	fprintf(f, "%u ", Header.FileSize);
	fprintf(f, "%u ", DIP.ImageWidth);
	fprintf(f, "%u ", DIP.ImageHeight);
	fprintf(f, "%hu", DIP.BitsPerPixel);
	fclose(f); fclose(f_from);
}
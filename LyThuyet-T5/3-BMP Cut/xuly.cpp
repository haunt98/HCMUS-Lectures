#include "xuly.h"

// Header and DIB
void readHeaderDIP(FILE *f, BitmapHeader &Header, BitmapDIP &DIP)
{
	if (!f)
		return;
	fseek(f, 0, SEEK_SET);
	fread(&Header, sizeof(BitmapHeader), 1, f);
	fread(&DIP, sizeof(BitmapDIP), 1, f);
}

void writeHeaderDIP(FILE *f, BitmapHeader Header, BitmapDIP DIP)
{
	fseek(f, 0, SEEK_SET);
	fwrite(&Header, sizeof(BitmapHeader), 1, f);
	fwrite(&DIP, sizeof(BitmapDIP), 1, f);
}

// Padding
void skipPadding(FILE *f, BitmapDIP DIP)
{
	if (!f)
		return;

	uint32_t padding = (4 - (DIP.ImageWidth * (DIP.BitsPerPixel / 8) % 4)) % 4;
	uint32_t temp;
	fread(&temp, 1, padding, f);
}

void writePadding(FILE *f, BitmapDIP DIP)
{
	uint32_t padding = (4 - (DIP.ImageWidth * (DIP.BitsPerPixel / 8) % 4)) % 4;
	uint32_t temp = 0;
	fwrite(&temp, 1, padding, f);
}

// Pixel Array
void readPixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray &Array)
{
	if (!f)
		return;
	fseek(f, Header.BitMapOffset, SEEK_SET);
	// set up array
	Array.row = DIP.ImageHeight;
	Array.column = DIP.ImageWidth;

	Array.dataArray = new Pixel *[Array.row];
	for (uint32_t i = 0; i < Array.row; ++i)
	{
		Array.dataArray[Array.row - 1 - i] = new Pixel[Array.column];
		fread(Array.dataArray[Array.row - 1 - i], sizeof(Pixel), Array.column, f);
		skipPadding(f, DIP);
	}
}

void writePixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray Array)
{
	fseek(f, Header.BitMapOffset, SEEK_SET);

	for (uint32_t i = 0; i < Array.row; ++i)
	{
		fwrite(Array.dataArray[Array.row - 1 - i], sizeof(Pixel), Array.column, f);
		writePadding(f, DIP);
	}
}

void cutBMP(char *filename, uint32_t cutHeight, uint32_t cutWidth)
{
	if (cutHeight == 0 || cutWidth == 0)
	{
		cout << "Error" << endl;
		return;
	}

	FILE *f = fopen(filename, "rb");
	if (!f)
		return;

	// read info
	BitmapHeader Header; BitmapDIP DIP; PixelArray Array;
	readHeaderDIP(f, Header, DIP);
	readPixelArray(f, Header, DIP, Array);

	// new Height and Width
	BitmapHeader newHeader = Header; BitmapDIP newDIP = DIP;
	if (cutHeight)
		newDIP.ImageHeight = DIP.ImageHeight / cutHeight;
	if (cutWidth)
		newDIP.ImageWidth = DIP.ImageWidth / cutWidth;
	// new padding
	uint32_t new_padding = (4 - (newDIP.ImageWidth * (newDIP.BitsPerPixel / 8) % 4)) % 4;
	// new file size
	newHeader.FileSize = sizeof(BitmapHeader) + sizeof(BitmapDIP) + newDIP.ImageHeight * newDIP.ImageWidth * (newDIP.BitsPerPixel / 8) + newDIP.ImageHeight * new_padding;
	//newDIP.PixelArraySize = (((newDIP.ImageWidth * newDIP.BitsPerPixel + 31) & ~31) / 8) * newDIP.ImageHeight;
	newDIP.PixelArraySize = newDIP.ImageHeight*(newDIP.ImageWidth * 3 + new_padding);

	// cut Pixel Array

	uint32_t i, j; PixelArray newArray;
	for (i = 1; i <= cutHeight; ++i)
		for (j = 1; j <= cutWidth; ++j)
		{
			creatSubArray(Array, newArray, i, j, cutHeight, cutWidth);
			FILE *out = fopen(newName(filename, i, j, cutHeight, cutWidth), "wb");
			writeHeaderDIP(out, newHeader, newDIP);
			writePixelArray(out, newHeader, newDIP, newArray);
		}
}

// return "source_ij.bmp"
char *newName(char *source, uint32_t i, uint32_t j, uint32_t cutHeight, uint32_t cutWidth)
{
	char *p, *q, *n_source;

	// cut the .bmp
	n_source = new char[strlen(source)];
	strcpy(n_source, source);
	n_source[strlen(source) - 4] = '\0';

	// add _ij and add .bmp back
	if (cutHeight == 1 && cutWidth != 1)
	{
		p = new char[strlen(source) + 3];
		strcpy(p, n_source);
		strcat(p, "_");
		q = new char[2];
		q[0] = '0' + j; q[1] = '\0';
		strcat(p, q);
		strcat(p, ".bmp");
	}
	else if (cutWidth == 1 && cutHeight != 1)
	{
		p = new char[strlen(source) + 3];
		strcpy(p, n_source);
		strcat(p, "_");
		q = new char[2];
		q[0] = '0' + i; q[1] = '\0';
		strcat(p, q);
		strcat(p, ".bmp");
	}
	else if (cutHeight != 1 && cutWidth != 1)
	{
		p = new char[strlen(source) + 4];
		strcpy(p, n_source);
		strcat(p, "_");
		q = new char[3];
		q[0] = '0' + i; q[1] = '0' + j; q[2] = '\0';
		strcat(p, q);
		strcat(p, ".bmp");
	}
	else
	{
		p = new char[strlen(source) + 2];
		strcpy(p, n_source);
		strcat(p, "_");
		strcat(p, ".bmp");
	}
	return strdup(p);
}

void creatSubArray(PixelArray oldArray, PixelArray &subArray, uint32_t i, uint32_t j, uint32_t cutHeight, uint32_t cutWidth)
{
	uint32_t a, b;
	subArray.row = oldArray.row / cutHeight;
	subArray.column = oldArray.column / cutWidth;

	// copy to sub array
	subArray.dataArray = new Pixel *[subArray.row];
	for (a = 0; a < subArray.row; ++a)
	{
		subArray.dataArray[a] = new Pixel[subArray.column];
		for (b = 0; b < subArray.column; ++b)
			subArray.dataArray[a][b] = oldArray.dataArray[a + (i - 1)*subArray.row][b + (j - 1)*subArray.column];
	}
}

uint32_t char_to_int(char *str)
{
	uint32_t temp = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			temp = temp * 10 + *str - '0';
		++str;
	}
	return temp;
}
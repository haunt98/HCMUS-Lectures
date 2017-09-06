#pragma pack(1)
#include <stdio.h>
#include <inttypes.h>
#include <Windows.h>
#define BUFFER 1000
#define MAX 100

struct BitmapHeader{
	char FileType[2];
	uint32_t FileSize;
	uint16_t Reversed1;
	uint16_t Reversed2;
	uint32_t BitMapOffset;
};

struct BitmapDIP{
	uint32_t DIPSize;
	uint32_t ImageWidth;
	uint32_t ImageHeight;
	uint16_t ColorPlanes;
	uint16_t BitsPerPixel;
	uint32_t Compression;
	uint32_t PixelArraySize;
	uint32_t HorizontalResolution;
	uint32_t VerticalResolution;
	uint32_t Colors;
	uint32_t ImportantColors;
};

struct Pixel{
	uint8_t Blue;
	uint8_t Green;
	uint8_t Red;
};

struct PixelArray{
	Pixel **dataArray;
	uint32_t row;
	uint32_t column;
};

bool isBMP(char *filename);

void printInfo(char *filename);

void copyFile(FILE *input, FILE *output);

void readPixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray &Array);

void writePixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray Array);

void changePixelArray(PixelArray &A);

void changeRedtoYellow(char *input, char *ouput);

void freePixelArray(PixelArray &A);

void displayBMP(char *filename);

void inputText(char *filename, char *linkFrom, char *linkTo, Pixel &PixelFrom, Pixel &PixelTo);

void outputText(char *filename, char *linkFrom, char *linkTo, Pixel PixelFrom, Pixel PixelTo);
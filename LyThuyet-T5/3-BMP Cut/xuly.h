#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#pragma pack(1)
#include <iostream>
#include <inttypes.h>
#include <Windows.h>
#include <string.h>
using namespace std;

#define DEBUG 1

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

void readHeaderDIP(FILE *f, BitmapHeader &Header, BitmapDIP &DIP);
void writeHeaderDIP(FILE *f, BitmapHeader Header, BitmapDIP DIP);

void skipPadding(FILE *f, BitmapDIP DIP);
void writePadding(FILE *f, BitmapDIP DIP);

void readPixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray &Array);
void writePixelArray(FILE *f, BitmapHeader Header, BitmapDIP DIP, PixelArray Array);

void cutBMP(char *filename, uint32_t cutHeight, uint32_t cutWidth);

char *newName(char *source, uint32_t i, uint32_t j, uint32_t cutHeight, uint32_t cutWidth);

void creatSubArray(PixelArray oldArray, PixelArray &subArray, uint32_t i, uint32_t j, uint32_t cutHeight, uint32_t cutWidth);

uint32_t char_to_int(char *str);
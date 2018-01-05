#include <Windows.h>
#include <iostream>

#define YELLOW RGB(255, 255, 0)

HWND console = GetConsoleWindow();
HDC hdc = GetDC(console);

struct SetPoint {
	int x, y;
};

void drawLine(HDC hdc, SetPoint A, SetPoint B, COLORREF color)
{
	if (abs(A.x - B.x) <= 1 && abs(A.y - B.y) <= 1)
		SetPixel(hdc, A.x, A.y, color);
	else {
		SetPoint mid;
		mid.x = (A.x + B.x) / 2;
		mid.y = (A.y + B.y) / 2;
		drawLine(hdc, A, mid, color);
		drawLine(hdc, mid, B, color);
	}
}

void drawCircle(HDC hdc, SetPoint O, int R, COLORREF color)
{
	return;
}

int main(void)
{
	SetPoint A = SetPoint{100, 100};
	SetPoint B = SetPoint{300, 300};

	drawLine(hdc, A, B, YELLOW);
	// ReleaseDC(console, hdc);
	return 0;
}
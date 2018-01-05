#include "Console.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void fixedOutputWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void hideCursor()
{
	static const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = {1, false};
	SetConsoleCursorInfo(hConsole, &cursor);
}

void clearScreen()
{
	COORD topLeft = {0, 0};

	// Done once so use static
	static const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;

	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter(hConsole, TEXT(' '), length, topLeft,
				   &written);

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, topLeft,
				   &written);

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition(hConsole, topLeft);
}

void setColor(Colors cl)
{
	static const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, cl);
}
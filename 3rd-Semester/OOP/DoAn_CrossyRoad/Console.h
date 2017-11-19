#ifndef CONSOLE_H
#define CONSOLE_H

enum Colors
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARKGREY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

void fixedOutputWindow();
void hideCursor();
void clearScreen();
void setColor(Colors cl);

#endif
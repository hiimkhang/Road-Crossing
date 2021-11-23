#ifndef _console_h_
#define _console_h_

#include <windows.h>

void gotoxy(int x, int y);

void setScreenSize(SHORT x, SHORT y, SHORT width, SHORT height);

void drawBoard(int color);
#endif // !_console_h_

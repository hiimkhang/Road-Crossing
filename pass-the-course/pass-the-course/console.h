#ifndef _console_h_
#define _console_h_

#include <windows.h>
#include <iostream>
using namespace std;

#define Black			0
#define DarkBlue		1
#define DarkGreen		2
#define DarkCyan		3
#define DarkRed			4
#define DarkPink		5
#define DarkYellow		6
#define DarkWhite		7
#define Gray			8
#define Blue			9
#define Green			10
#define Cyan			11
#define Red				12
#define Pink			13
#define Yellow			14
#define White			15
#define defaultColor	7 

void gotoxy(int x, int y);

void setScreenSize(SHORT x, SHORT y, SHORT width, SHORT height);

void fixConsoleWindow();

void Textcolor(int color);

void clrscr();

void drawBoard(int color);

void ShowConsoleCursor(bool showFlag);
#endif // !_console_h_

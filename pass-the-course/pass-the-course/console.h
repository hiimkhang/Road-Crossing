#ifndef _console_h_
#define _console_h_

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <mmsystem.h>
#include <filesystem>

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

#define DOWN_BLACK_PIECE char(220)
#define UP_BLACK_PIECE char(223)
#define VERTICAL_BLACK_PIECE char(219)
#define MIDDLE_SMALL_BLACK_PIECE char(254)

#define HORIZONTAL_PALE_PIECE char(205);
#define VERTICAL_PALE_PIECE char(186);
#define UP_LEFT_CORNER_PALE_PIECE char(201)
#define UP_RIGHT_CORNER_PALE_PIECE char(187)
#define DOWN_LEFT_CORNER_PALE_PIECE char(200)
#define DOWN_RIGHT_CORNER_PALE_PIECE char(188)

#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_ESC 27
#define KEY_ENTER 13

void gotoxy(int x, int y);

void setScreenSize(SHORT x, SHORT y, SHORT width, SHORT height);

void resizeConsole(int width, int height);

void fixConsoleWindow();

void Textcolor(int color);

void clrscr();

void drawBoard(int color);

void ShowConsoleCursor(bool showFlag);



#endif // !_console_h_

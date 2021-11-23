#include "console.h"

void gotoxy(int x, int y) 
{
	 COORD coord;
	 coord.X = x;
	 coord.Y = y;
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
}

void setScreenSize(SHORT x, SHORT y, SHORT width, SHORT height)
{
	HWND consoleWindow = GetConsoleWindow();
	MoveWindow(GetConsoleWindow(), x, y, width, height, TRUE);
}

void drawBoard(int color)
{

}

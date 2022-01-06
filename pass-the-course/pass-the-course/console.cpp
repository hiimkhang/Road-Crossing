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

void resizeConsole(int width, int height) {
	HWND console = GetConsoleWindow();
	RECT edge;
	GetWindowRect(console, &edge);
	MoveWindow(console, edge.left, edge.top, width, height, TRUE);
}

void drawBoard(int color)
{
	int a = 5;
	int b = 2;
	gotoxy(a, b);
	Textcolor(color);
	// ve duong ngang
	cout << char(220);
	for (int i = 1; i <= 121; i++) {
		if (i == 95) cout << char(220);
		cout << char(220);

	}
	cout << char(220) << endl;
	// ve doc
	for (int i = 1; i <= 36; i++) {
		gotoxy(a, b + i);

		for (int j = 1; j < 123; j++) {
			if (j == 85 || j == 122 || j == 1) cout << char(219);
			cout << " ";

		}
		if ((i) % 6 == 0 && (i) != 0) {
			gotoxy(a + 1, b + i);
			for (int k = 1; k <= 84; k++) {
				if (k % 2 == 0 && k != 0) {
					cout << " ";
				}
				else
					cout << char(205);
			}
		}
	}
	// ve canh day
	gotoxy(a, 38);
	cout << char(223);
	for (int i = 1; i <= 121; i++) {
		if (i == 95) cout << char(223);
		cout << char(223);
	}
	cout << char(223);

}

void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}
void Textcolor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}

void fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void clearHeart(int a, int b) {

	gotoxy(a, b);
	cout << "     "  << endl;
	gotoxy(a, b + 1);
	cout << "     " << endl;
	gotoxy(a, b + 2);
	cout << "     " << endl;
	gotoxy(a, b + 3);
	cout << "     " << endl;

}
#include "interface.h"



void DisableCtrButton(bool Close, bool Min, bool Max)
{
	HWND hWnd = GetConsoleWindow();
	HMENU hMenu = GetSystemMenu(hWnd, false);

	if (Close == 1)
	{
		DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
	}
	if (Min == 1)
	{
		DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
	}
	if (Max == 1)
	{
		DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
	}
}

void gotoxy(short posX, short posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}

void setTextColor(long color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdout, color);
}

void drawRec(long x, long y, long posX, long posY)
{
	x = x + 2;
	y = y * 4 + 1;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(218);
		else if (i == y) cout << char(191);
		else cout << char(196);
	}
	for (long i = 2; i < x; i++)
	{
		posY++;
		gotoxy(posX, posY);
		for (long j = 1; j <= y; j++)
		{
			if (j == 1 || j == y) cout << char(179);
			else cout << ' ';
		}
	}
	posY++;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(192);
		else if (i == y) cout << char(217);
		else cout << char(196);
	}
}

void drawRec2(long x, long y, long posX, long posY)
{
	x = x + 2;
	y = y * 4 + 1;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == y) cout << char(187);
		else cout << char(205);
	}
	for (long i = 2; i < x; i++)
	{
		posY++;
		gotoxy(posX, posY);
		for (long j = 1; j <= y; j++)
		{
			if (j == 1 || j == y) cout << char(186);
			else cout << ' ';
		}
	}
	posY++;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(200);
		else if (i == y) cout << char(188);
		else cout << char(205);
	}
}

void drawRec3(long x, long y, long posX, long posY)
{
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == y) cout << char(187);
		else cout << char(205);
	}
	for (long i = 2; i < x; i++)
	{
		posY++;
		gotoxy(posX, posY);
		for (long j = 1; j <= y; j++)
		{
			if (j == 1 || j == y) cout << char(186);
			else cout << ' ';
		}
	}
	posY++;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(200);
		else if (i == y) cout << char(188);
		else cout << char(205);
	}
}



bool isOK(string str)
{
	setTextColor(12);
	drawRec3(10, (str.size() <= 32 ? 34 : str.size() + 2), 50, 18);
	gotoxy(52, 19); setTextColor(7); cout << "Are you sure with your choice?";
	gotoxy(51, 20); setTextColor(7); cout << str;

	gotoxy(52, 25); setTextColor(11); cout << "Yes";
	gotoxy(52, 26); cout << char(22);

	gotoxy(80, 25); setTextColor(7); cout << "No";
	gotoxy(80, 26); cout << char(22);

	long cnt = 1;
	while (1)
	{
		char c = _getch();
		
		if (c == char(75) || c == 'a' || c == 'A' || c == char(77) || c == 'd' || c == 'D') cnt = !cnt;

		if (c == 'N' || c == 'n')
		{
			gotoxy(52, 25); setTextColor(7); cout << "Yes";
			gotoxy(52, 26); cout << char(22);

			gotoxy(80, 25); setTextColor(11); cout << "No";
			gotoxy(80, 26); cout << char(22);
			return false;
		}
		else if (c == 'Y' || c == 'y')
		{
			gotoxy(52, 25); setTextColor(11); cout << "Yes";
			gotoxy(52, 26); cout << char(22);

			gotoxy(80, 25); setTextColor(7); cout << "No";
			gotoxy(80, 26); cout << char(22);
			return true;
		}

		if (c == char(13))
		{
			if (cnt == 1) return true;
			else return false;
		}

		if (cnt == 1)
		{
			gotoxy(52, 25); setTextColor(11); cout << "Yes";
			gotoxy(52, 26); cout << char(22);

			gotoxy(80, 25); setTextColor(7); cout << "No";
			gotoxy(80, 26); cout << char(22);
		}
		if (cnt == 0)
		{
			gotoxy(52, 25); setTextColor(7); cout << "Yes";
			gotoxy(52, 26); cout << char(22);

			gotoxy(80, 25); setTextColor(11); cout << "No";
			gotoxy(80, 26); cout << char(22);
		}
	}
	return true;
}


void showInput(bool show, HANDLE hStdin, DWORD mode)
{


	if (show)
	{
		SetConsoleMode(hStdin, mode & (~ENABLE_INSERT_MODE));
	}
	else
	{
		SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
	}
}

//warning(a, 9, 20, 59, 19);
void warning(string warningText, long x, long y, long posX, long posY) {

	x = x + 2;
	y = y * 4 + 1;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(201);
		else if (i == y) cout << char(187);
		else cout << char(205);
	}

	for (long i = 2; i <= x; i++)
	{
		posY++;
		gotoxy(posX, posY);
		for (long j = 1; j <= y; j++)
		{
			if (j == 1 || j == y) cout << char(186);
			else if (i >= 2 && i <= 7 && j <= 6 && j >= 3) cout << char(219);
			else if ((i == 2 && j == 7) || (i == 9 && j == 7)) cout << char(187);
			else if ((i > 2 && i <= 7 && j == 7) || (i == 10 && j == 7)) cout << char(186);
			else if ((i == 8 && j == 7) || (i == 11 && j == 7)) cout << char(188);
			else if ((i == 8 && j > 4 && j < 7) || (i == 11 && j > 4 && j < 7)) cout << char(205);
			else if ((i == 8 && j == 4) || (i == 11 && j == 4)) cout << char(200);
			else if (i > 8 && i <= x - 1 && j <= 6 && j >= 3) cout << char(219);

			else cout << ' ';
		}
	}
	gotoxy(posX + 38, posY - 4);
	cout << warningText;
	posY++;
	gotoxy(posX, posY);
	for (long i = 1; i <= y; i++)
	{
		if (i == 1) cout << char(200);
		else if (i == y) cout << char(188);
		else cout << char(205);
	}
}

void printSettingBox(roll* setting, long n)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	for (long i = 0; i < n; i++)
	{
		SetConsoleTextAttribute(hStdout, setting[i].color);
		gotoxy(setting[i].x, setting[i].y);
		cout << setting[i].message;
	}
}

void wait(int seconds)
{
	clock_t ew;
	ew = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < ew) {}
}

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void clrscr()
{
	COORD origin = { 0, 0 };
	unsigned long len;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	unsigned long size;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);


	GetConsoleScreenBufferInfo(handle, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(handle, TEXT(' '), size, origin, &len);
	FillConsoleOutputAttribute(handle, csbi.wAttributes, size, origin, &len);
	SetConsoleCursorPosition(handle, origin);
}
void gotoxy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void clear(int a, int b, int c, int d)
{
	for (int i = a; i <= b; i++)
	{
		for (int j = c; j <= d; j++)
		{
			gotoxy(j, i);
			cout << ' ';
		}
	}
}
void welcome()
{
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { SetWindowPos(hwnd, 0, 0, 0, 2000, 700, SWP_SHOWWINDOW | SWP_NOMOVE); }
	setColor(15);
	gotoxy(0, 0);
	cout << char(201);
	gotoxy(176, 0);
	cout << char(187);
	gotoxy(0, 39);
	cout << char(200);
	gotoxy(176, 39);
	cout << char(188);
	for (int i = 1; i < 176; i++)
	{
		gotoxy(i, 0);
		cout << char(205);
	}
	for (int i = 1; i < 39; i++)
	{
		gotoxy(0, i);
		cout << char(186);
	}
	for (int i = 1; i < 39; i++)
	{
		gotoxy(176, i);
		cout << char(186);
	}
	for (int i = 1; i < 176; i++)
	{
		gotoxy(i, 39);
		cout << char(205);
	}

	gotoxy(37, 1);
	cout << "			    __    __   _____   __      _____   _____   __  __   _____  ";
	gotoxy(37, 2);
	cout << "			   |  |/\\|  | |  ___| |  |    /     \\ /     \\\ |  \\/  | |  ___| ";
	gotoxy(37, 3);
	cout << "			   |        | |  ___| |  |__  | <---< |  |  | |      | |  ___| ";
	gotoxy(37, 4);
	cout << "			    \\__/\\__/  |_____| |_____| \\_____/ \\_____/ |_|\\/|_| |_____| ";
	gotoxy(30, 10);
	cout << "  	                          &&&&&&&&7                       $&&&&&$";
	gotoxy(30, 11);
	cout << "                                    &&&&&&&&&c                   &&&&&&&$";
	gotoxy(30, 12);
	cout << "                                     @&&&&&$&&&&                ?&&&&&&&$";
	gotoxy(30, 13);
	cout << "                                      &&&&&&&&&&&&             &&&&&&&&@";
	gotoxy(30, 14);
	cout << "                                        &&&&&&&&&&&&c         &&&&&&&&&&";
	gotoxy(30, 15);
	cout << "                                          &&&&&&&&&&&&       &&&&&&&&&";
	gotoxy(30, 16);
	cout << "                                            c&&&&&&&&&&&    &&&&&&&&&";
	gotoxy(30, 17);
	cout << "                                             &&&&&$&&&&&7   &&&&&&&&&7";
	gotoxy(30, 18);
	cout << "                                              7&&&&&&&&&&  &&&&&&&&&";
	gotoxy(30, 19);
	cout << "                                                &&&&&&&&  &&&&&&&";
	gotoxy(30, 20);
	cout << "                                                      $&&&&&&&&&&&";
	gotoxy(30, 21);
	cout << "                                                  &&&&&&&&&&&&&&&&";
	gotoxy(30, 22);
	cout << "                                                &&&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 23);
	cout << "                                              &&&&&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 24);
	cout << "                                            &&&@    &&&&&&&&&&&&&&&&";
	gotoxy(30, 25);
	cout << "                                           &&&&      &&&&&&&&&&&&&&&&";
	gotoxy(30, 26);
	cout << "                                          &&&&&&    &&&&&&&&&&&&&&&&&";
	gotoxy(30, 27);
	cout << "                                          &&&&&&&&&&&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 28);
	cout << "                                          &&&&&&&&&&&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 29);
	cout << "                                           &&&&&&&&&&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 30);
	cout << "                                             &&&&&&&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 31);
	cout << "                                               7&&&&&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 32);
	cout << "                                                  &&&&&&&&&&&&&&&&&&&";
	gotoxy(30, 33);
	cout << "                                                   &&&&&|-O-|&&&&&";

	setColor(4);
	gotoxy(35, 5);
	cout << ",-._.-. ";
	gotoxy(34, 6);
	cout << "/_,._,._\\ ";
	gotoxy(34, 7);
	cout << "\\`-._.' / ";
	gotoxy(35, 8);
	cout << "\\_____/ ";

	gotoxy(51, 19);
	cout << "'.----'`v'`----.'";
	gotoxy(52, 20);
	cout << "\\`----._.----'/";
	gotoxy(53, 21);
	cout << "`.--.___.--.'";
	gotoxy(54, 22);
	cout << " `-.___.-'";
	
	setColor(12);
	gotoxy(131, 13);
	cout << ".. ..";
	gotoxy(129, 14);
	cout << ".'  `  `.";
	gotoxy(127, 15);
	cout << ".'_.-...-._`.";
	gotoxy(128, 16);
	cout << "`.       .'";
	gotoxy(130, 17);
	cout << "`-...-'";

	setColor(13);
	gotoxy(131, 22);
	cout << "***     ***";
	gotoxy(129, 23);
	cout << "**   ** **   **";
	gotoxy(128, 24);
	cout << "*       *       *";
	gotoxy(128, 25);
	cout << "*               *";
	gotoxy(129, 26);
	cout << "*             *";
	gotoxy(129, 27);
	cout << " **         **";
	gotoxy(132, 28);
	cout << "**     **";
	gotoxy(133, 29);
	cout << " ** **";
	gotoxy(136, 30);
	cout << "*";

	setColor(1);
	gotoxy(122, 8);
	cout << " |";
	gotoxy(122, 9);
	cout << "-o-";
	gotoxy(122, 10);
	cout << " |";

	gotoxy(110, 17);
	cout << " |";
	gotoxy(110, 18);
	cout << "-o-";
	gotoxy(110, 19);
	cout << " |";

	gotoxy(107, 25);
	cout << " |";
	gotoxy(107, 26);
	cout << "-o-";
	gotoxy(107, 27);
	cout << " |";

	setColor(9);
	gotoxy(61, 12);
	cout << " |";
	gotoxy(61, 13);
	cout << "-o-";
	gotoxy(61, 14);
	cout << " |";

	gotoxy(35, 22);
	cout << " |";
	gotoxy(35, 23);
	cout << "-o-";
	gotoxy(35, 24);
	cout << " |";

	setColor(15);
	for (int i = 60; i <= 78; i++)
	{
		gotoxy(i, 6);
		cout << char(219);
	}

	cout << "33,3%";

	wait(1);
	clear(2, 38, 2, 55);
	clear(18, 22, 50, 74);
	clear(8, 38, 2, 65);
	clear(8, 38, 105, 165);
	clear(18, 22, 50, 76);
	////////////////////////////////////////////////////////////////////////////////turn 2:
	setColor(12);
	gotoxy(109, 25);
	cout << ",-._.-. ";
	gotoxy(108, 26);
	cout << "/_,._,._\\ ";
	gotoxy(108, 27);
	cout << "\\`-._.' / ";
	gotoxy(109, 28);
	cout << "\\_____/ ";

	gotoxy(120, 8);
	cout << "'.----'`v'`----.'";
	gotoxy(121, 9);
	cout << "\\`----._.----'/";
	gotoxy(122, 10);
	cout << "`.--.___.--.'";
	gotoxy(123, 11);
	cout << " `-.___.-'";

	setColor(4);
	gotoxy(56, 13);
	cout << ".. ..";
	gotoxy(54, 14);
	cout << ".'  `  `.";
	gotoxy(52, 15);
	cout << ".'_.-...-._`.";
	gotoxy(53, 16);
	cout << "`.       .'";
	gotoxy(55, 17);
	cout << "`-...-'";

	setColor(13);
	gotoxy(22, 22);
	cout << "***     ***";
	gotoxy(20, 23);
	cout << "**   ** **   **";
	gotoxy(19, 24);
	cout << "*       *       *";
	gotoxy(19, 25);
	cout << "*               *";
	gotoxy(20, 26);
	cout << "*             *";
	gotoxy(20, 27);
	cout << " **         **";
	gotoxy(23, 28);
	cout << "**     **";
	gotoxy(24, 29);
	cout << " ** **";
	gotoxy(27, 30);
	cout << "*";

	setColor(9);
	gotoxy(122, 33);
	cout << " |";
	gotoxy(122, 34);
	cout << "-o-";
	gotoxy(122, 35);
	cout << " |";

	gotoxy(135, 17);
	cout << " |";
	gotoxy(135, 18);
	cout << "-o-";
	gotoxy(135, 19);
	cout << " |";

	setColor(1);
	gotoxy(112, 12);
	cout << " |";
	gotoxy(112, 13);
	cout << "-o-";
	gotoxy(112, 14);
	cout << " |";

	gotoxy(58, 26);
	cout << " |";
	gotoxy(58, 27);
	cout << "-o-";
	gotoxy(58, 28);
	cout << " |";

	gotoxy(27, 14);
	cout << " |";
	gotoxy(27, 15);
	cout << "-o-";
	gotoxy(27, 16);
	cout << " |";

	setColor(15);
	for (int i = 60; i <= 95; i++)
	{
		gotoxy(i, 6);
		cout << char(219);
	}

	cout << "66,6%";

	wait(1);
	clear(8, 38, 2, 64);
	clear(8, 38, 105, 165);
	/////////////////////////////////////////////////////////////////////turn 3:
	for (int i = 60; i <= 116; i++)
	{
		gotoxy(i, 6);
		cout << char(219);
	}
	cout << "99,9%";
	for (int i = 1; i < 6; i++)
	{
		wait(0.2);
		setColor(i);
		gotoxy(112, 11);
		cout << "    ,(())),";
		gotoxy(112, 12);
		cout << "   '(('''))'";
		gotoxy(112, 13);
		cout << "   '(|o_o|)'";
		gotoxy(112, 14);
		cout << "     : = :";
		gotoxy(112, 15);
		cout << "     _) (_";
		gotoxy(112, 16);
		cout << "   /`_ V _`\\ ";
		gotoxy(112, 17);
		cout << "  / (_   _) \\ ";
		gotoxy(112, 18);
		cout << " / / )   ( \\ \\ ";
		gotoxy(112, 19);
		cout << " \\ \\/_____\\/ /";
		gotoxy(112, 20);
		cout << "  \\_)__.__(_/";
		gotoxy(112, 21);
		cout << "   |  \\_/  )";
		gotoxy(112, 22);
		cout << "    \\ _/__/";
		gotoxy(112, 23);
		cout << "     \/   /";
		gotoxy(112, 24);
		cout << "     (  ;";
		gotoxy(112, 25);
		cout << "      \\  \\ ";
		gotoxy(112, 26);
		cout << "       \\  \\";
		gotoxy(112, 27);
		cout << "        ))"")-)";
		gotoxy(112, 28);
		cout << "        ((__/| * ";

		gotoxy(36, 12);
		cout << "   .&&&&&& / )";
		gotoxy(36, 13);
		cout << "   .&&&/ \\ |/";
		gotoxy(36, 14);
		cout << "   .&& <,( |\\";
		gotoxy(36, 15);
		cout << "    &&  _/ | )";
		gotoxy(36, 16);
		cout << "   _ ) &._/ /";
		gotoxy(36, 17);
		cout << "  /  )__| .'";
		gotoxy(36, 18);
		cout << " /./| _)_)";
		gotoxy(36, 19);
		cout << "( | \\.--|";
		gotoxy(36, 20);
		cout << " \\|  ) !|";
		gotoxy(36, 21);
		cout << " /| /.__|";
		gotoxy(36, 22);
		cout << "(_// _\\_/______";
		gotoxy(36, 23);
		cout << "  (            )";
		gotoxy(36, 24);
		cout << "   '..____.-'/ |";
		gotoxy(36, 25);
		cout << "    \\  |    (  |";
		gotoxy(36, 26);
		cout << "     \\ /     \\ |";
		gotoxy(36, 27);
		cout << "     / |      )|";
		gotoxy(36, 28);
		cout << "    (  |     / |";
		gotoxy(36, 29);
		cout << "     \\ |      \\|";
		gotoxy(36, 30);
		cout << "      )|";
		gotoxy(36, 31);
		cout << "     / |";
		gotoxy(36, 32);
		cout << "     \\ |";
	}
	wait(2);
	return;
}

void exit()
{
	setColor(11);
	gotoxy(0, 0);
	cout << char(201);
	gotoxy(176, 0);
	cout << char(187);
	gotoxy(0, 39);
	cout << char(200);
	gotoxy(176, 39);
	cout << char(188);
	for (int i = 1; i < 176; i++)
	{
		gotoxy(i, 0);
		cout << char(205);
	}
	for (int i = 1; i < 39; i++)
	{
		gotoxy(0, i);
		cout << char(186);
	}
	for (int i = 1; i < 39; i++)
	{
		gotoxy(176, i);
		cout << char(186);
	}
	for (int i = 1; i < 176; i++)
	{
		gotoxy(i, 39);
		cout << char(205);
	}

	setColor(9);
	gotoxy(58, 5);
	cout << char(219) << char(219) << char(219) << char(219) << " " << char(219) << char(219) << " " << char(219) << char(219) << "  " << char(220) << char(219) << char(219) << char(219) << char(220) << "  " << char(219) << char(219) << char(220) << " " << char(219) << char(219) << " " << char(219) << char(219) << " " << char(220) << char(219) << char(219) << endl;
	gotoxy(58, 6);
	cout << " " << char(219) << char(219) << "  " << char(219) << char(219) << char(220) << char(219) << char(219) << " " << char(219) << char(219) << char(223) << " " << char(223) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(220) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(219) << char(223) << endl;
	gotoxy(58, 7);
	cout << " " << char(219) << char(219) << "  " << char(219) << char(219) << char(223) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(223) << char(219) << char(219) << char(219) << " " << char(219) << char(219) << char(219) << char(219) << char(220) << endl;
	gotoxy(58, 8);
	cout << " " << char(219) << char(219) << "  " << char(219) << char(219) << " " << char(219) << char(219) << " " << char(219) << char(219) << "   " << char(219) << char(219) << " " << char(219) << char(219) << "  " << char(219) << char(219) << " " << char(219) << char(219) << " " << char(223) << char(219) << char(219) << endl << endl;

	gotoxy(95, 5);
	cout << char(219) << char(219) << char(220) << "  " << char(220) << char(219) << char(219) << "  " << char(220) << char(219) << char(219) << char(219) << char(220) << "  " << char(219) << char(219) << "  " << char(219) << char(219) << endl;
	gotoxy(95, 6);
	cout << " " << char(223) << char(219) << char(219) << char(219) << char(219) << char(223) << "  " << char(219) << char(219) << char(223) << " " << char(223) << char(219) << char(219) << " " << char(219) << char(219) << "  " << char(219) << char(219) << endl;
	gotoxy(95, 7);
	cout << "   " << char(219) << char(219) << "    " << char(219) << char(219) << char(220) << " " << char(220) << char(219) << char(219) << " " << char(219) << char(219) << "  " << char(219) << char(219) << endl;
	gotoxy(95, 8);
	cout << "   " << char(219) << char(219) << "     " << char(223) << char(219) << char(219) << char(219) << char(223) << "  " << char(223) << char(219) << char(219) << char(219) << char(219) << char(223);

	gotoxy(120, 5);
	cout << char(219) << char(219) << endl;
	gotoxy(120, 6);
	cout << char(219) << char(219) << endl;
	gotoxy(120, 7);
	cout << char(220) << char(220) << endl;
	gotoxy(120, 8);
	cout << char(223) << char(223) << endl;

	gotoxy(61, 15);
	cout << "               xxxx                  xxxx";
	gotoxy(61, 16);
	cout << "            x        x            x        x";
	gotoxy(61, 17);
	cout << "          x           x         x           x";
	gotoxy(61, 18);
	cout << "                xx                    xx";
	gotoxy(61, 19);
	cout << "               x    x                x    x";
	gotoxy(61, 20);
	cout << "              x      x              x      x";
	gotoxy(61, 21);
	cout << "              x      x              x      x";
	gotoxy(61, 22);
	cout << "              x    xxx              x    xxx";
	gotoxy(61, 23);
	cout << "              x   xxxx              x   xxxx";
	gotoxy(61, 24);
	cout << "               x xxxx                x xxxx";
	gotoxy(61, 25);
	cout << "                xxx         xxx       xxx";
	gotoxy(61, 26);
	cout << "                           xxxxx";
	gotoxy(61, 27);
	cout << "                           xxxxx";
	gotoxy(61, 28);
	cout << "            xx              xxx             xx";
	gotoxy(61, 29);
	cout << "          xx                                  xx";
	gotoxy(61, 30);
	cout << "        xxx                                    xxx";
	gotoxy(61, 31);
	cout << "           xx                                xx";
	gotoxy(61, 32);
	cout << "             xx                             xx";
	gotoxy(61, 33);
	cout << "               xxxx                      xxxx";
	gotoxy(61, 34);
	cout << "                    xxx               xxx";
	gotoxy(61, 35);
	cout << "                        xxxx     xxx";
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void ShowScrollbar(BOOL Show)
{
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}

void setScreenSize(SHORT x, SHORT y, SHORT width, SHORT height)
{
	HWND consoleWindow = GetConsoleWindow();
	MoveWindow(GetConsoleWindow(), x, y, width, height, TRUE);
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int inputKey()
{

	int key = _getch();

	if (key == 224)
	{
		key = _getch();
		return key;
	}

	return key;

}

int getColor() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
		return false;
	SHORT ret = info.wAttributes;
	return ret;
}

void setBackgroundColor(int BackC)
{

	WORD wColor = ((BackC & 0x0F) << 4) + (getColor() & 0x0F);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SetConsoleTextAttribute(hStdOut, wColor);
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		SetConsoleCursorPosition(hStdOut, coord);
	}
	return;
}
//void ellipses(int posX, int posY) {
//	int n = 46;
//
//	for (int i = 0; i < 5; i++) {
//		gotoxy(posX, posY);
//		Sleep(800);
//		if (i % 4 == 1) cout << char(n);
//		else if (i % 4 == 2) cout << char(n) << char(n);
//		else if (i % 4 == 3) cout << char(n) << char(n) << char(n);
//		else cout << "    ";
//	}
//}
void ellipses(int posX, int posY) 
{
	int n = 46;

	for (int i = 0; i < 60; i++) {
		gotoxy(posX, posY);
		Sleep(800);
		if (i % 4 == 1) cout << char(n);
		else if (i % 4 == 2) cout << char(n) << char(n);
		else if (i % 4 == 3) cout << char(n) << char(n) << char(n);
		else cout << "    ";
	}
}
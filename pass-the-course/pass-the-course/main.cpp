
#include <iostream>
#include <Windows.h>
#include <thread>
#include <conio.h>
<<<<<<< HEAD
=======
#include "CGame.h"
>>>>>>> 263100914b68528f4f6714c5d6df2b17f50779c6
#include "console.h"
using namespace std;

int e = 3;
<<<<<<< HEAD


=======
// already definded in console.h
//void gotoxy(int x, int y) {
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
>>>>>>> 263100914b68528f4f6714c5d6df2b17f50779c6
class Human
{
public:
    int curX = 7, curY = 7, preX = 0, preY = 0, step;
    void moveup()
    {
        preX = curX;
        preY = curY;
        curY -= 1;
    }
    void movedown()
    {
        preX = curX;
        preY = curY;
        curY += 1;
    }
    void moveleft()
    {
        preX = curX;
        preY = curY;
        curX -= 1;
    }
    void moveright()
    {
        preX = curX;
        preY = curY;
        curX += 1;
    }
    void print()
    {
        gotoxy(preX, preY);
        cout << "   ";
        gotoxy(preX, preY + 1);
        cout << "   ";
        gotoxy(preX, preY + 2);
        cout << "   ";
        //display human
        gotoxy(curX, curY);
        cout << "XXX";
        gotoxy(curX, curY + 1);
        cout << "XXX";
        gotoxy(curX, curY + 2);
        cout << "XXX";
    }
};
void obstacleMove(int& x, int y)
{
    gotoxy(x, y);
    cout << "   ";
    x += 1;
    if (x > 80)
        x = 0;
    gotoxy(x, y);
    cout << "ooo";
}
Human khang;
void subThread()
{
    int a = 1;//obstacle 1
    int b = 3; //obstacle 2
    int c = 5; //obstacle 3
    while (1)
    {
        obstacleMove(a, 3);
        obstacleMove(b, 6);
        obstacleMove(c, 9);
        khang.print();
        Sleep(100);
    }
}

int main()
{   

    setScreenSize(0, 0, 800, 650);
    gotoxy(30, 11);
    cout << "  X  ";
    gotoxy(30, 12);
    cout << "XXXXX";
    gotoxy(30, 13);
    cout << "XX XX";
    gotoxy(30, 14);
    cout << "XX XX";
    /*thread t1(subThread);
    while (1)
    {
        int x = toupper(_getch());
        switch (x)
        {
        case 'W':
            khang.moveup();
            break;
        case 'D':
            khang.moveright();
            break;
        case 'S':
            khang.movedown();
            break;
        case 'A':
            khang.moveleft();
            break;
        }
    }*/
    return 0;
}
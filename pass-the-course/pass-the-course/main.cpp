
#include <iostream>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include "CGame.h"
#include "console.h"
#include "Obstacle.h"

// #include "console.cpp"
using namespace std;

int e = 3;
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
    
    Obstacle *O1;

    O1 = new Rock(20, 20);
    O1->print();

    O1 = new Potion(70, 20);
    O1->print();

    gotoxy(12, 10);
    cout << "Cop's speed 2: ";
    O1 = new Cop(30, 10);
    O1->print();
    O1->move(2, 0);

    gotoxy(12, 18);
    cout << "Cop's speed 5: ";
    O1 = new Cop(30, 18);
    O1->print();
    O1->move(5, 0);

    cout << "\n\n\n\n\n";
    Textcolor(Black);
    // system("pause");
    return 0;
}

// gotoxy(30, 11);
    // cout << "  X  ";
    // gotoxy(30, 12);
    // cout << "XXXXX";
    // gotoxy(30, 13);
    // cout << "XX XX";
    // gotoxy(30, 14);
    // cout << "XX XX";
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

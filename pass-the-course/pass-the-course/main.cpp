
#include <iostream>
#include <Windows.h>
#include <thread>
#include <conio.h>
//#include "CGame.h"k
#include "console.h"
#include "Obstacle.h"
#include "Figure.h"

// #include "console.cpp"
using namespace std;

int e = 3;

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
    Textcolor(0);
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

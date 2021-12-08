
#include <iostream>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include "CGame.h"
#include "console.h"
#include "Obstacle.h"
#include "Figure.h"
#include <string>
#include <fstream>
using namespace std;

char MOVING;
bool IS_RUNNING = true;
CGame cg;

//int e = 3;

//void obstacleMove(int& x, int y)  // Danggggggg
//{
//    gotoxy(x, y);
//    cout << "   ";
//    x += 1;
//    if (x > 80)
//        x = 0;
//    gotoxy(x, y);
//    cout << "ooo";
//}

void exitGame(thread* t) {
    system("cls");
    IS_RUNNING = false;
    t->join();
}
void SubThread() {
    while (IS_RUNNING) {
        if (!cg.getPeople().getIsDead()) {
            //cg.updatePosPeople(MOVING);   // take the input form user -> assign to MOVING = temp -> update position
        }
        MOVING = ' ';   // reset the moving, stop the human, if user dont input -> the humam still stop
        cg.updatePosCLane(); // update the position of each obstacle in the list
        

        //cg.drawGame();    // draw the game box skeleton

        /*if (cg.getPeople().isImpact(cg.getListObstacle())) {

        }
        if (cg.getPeople().isFinish()) {

        }*/
        Sleep(100);
    }
}



int main() {

    int temp;
    fixConsoleWindow();
    cout << "enter sth to start\n";
    cin.get();
    cg.startGame();
    thread t1(SubThread);
    
    while (1) {
        cout << "Use WASD to move your character\n";
        temp = toupper(_getch());
        
        if (!cg.getPeople().getIsDead()) {
            if (temp == 27) {   // exit
                
            }
            else if (temp == 'P') { // pause game

            }
            else {  // continue / resume
                MOVING = temp;
            }
        }
        
    }

}


//int main()
//{
//    /*Figure cop(".//Figure//Obstacle//cop.txt");
//    cop.print(6, 6);*/
//    
//
//    ShowCursor(1);
//    setScreenSize(0, 0, 800, 650);
//
//    Obstacle* O1;
//
//    O1 = new Rock(20, 20);
//    O1->print();
//
//    O1 = new Potion(70, 20);
//    O1->print();
//
//    gotoxy(12, 10);
//    cout << "Cop's speed 2: ";
//    O1 = new Cop(30, 10);
//    O1->print();
//    O1->move(2, 0);
//
//    gotoxy(12, 18);
//    cout << "Cop's speed 5: ";
//    O1 = new Cop(30, 18);
//    O1->print();
//    O1->move(5, 0);
//
//    cout << "\n\n\n\n\n";
//    Textcolor(0);
//    // system("pause");
//    return 0;
//}




// gotoxy(30, 11);  // Danggggggggggg
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


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

auto t_start = std::chrono::high_resolution_clock::now();

void SubThread() {
    while (IS_RUNNING) {

        auto t_now = std::chrono::high_resolution_clock::now();
        double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_now - t_start).count();
        if (elapsed_time_ms > 3000) {   // every 3 second light will change
            t_start = t_now;
            //cout << "elapsed_time_ms: " << elapsed_time_ms << endl;
            cg.updateRedLight();
        }

        if (!cg.getPeople().getIsDead()) {
            cg.updatePosPeople(MOVING);     // take the input form user -> assign to MOVING = temp -> update position
        }
        MOVING = ' ';                       // reset the moving, stop the human, if user dont input -> the humam still stop
        cg.updatePosCLane();                // update the position of each obstacle in the list (move the clane)

        //cg.drawGame();                    // draw ?

        if (cg.isCollided()) {              // human collide with obstacle
            cout << "\n------------OH NO-------------\n";
            cout << "\n------------YOU LOSE-----------\n";
            cout << "Enter C to new game. S or other to exit and return to menu\n";
            char temp = _getch();
            if (toupper(temp) == 'C') {
                cg.resetGame();
            }
            else {
                // exit, return to menu
                //break;
            }
        }
        // method 1 - as pdf slide
        //if (cg.getPeople().isFinish()) {    
        //  cout << "\n------------YOU WIN-------------\n";
        //    // human touch the top line -> Viktory
        //    // Ask them if they want to continue with new level or not
        //    // use cg.getPeople().isFinish() because they will create new people if the previous has been victory
        //    // come to new level
        //    // player will play with new human, cg.getPeople() now is new People
        //}

        // method 2
        if (cg.isFinish()) {
            cout << "\n------------YOU WIN-------------\n";
            cout << "\n------------NEW LEVEL-----------\n";
            // we reset the human state (curX, curY = 0), isFinish = false, isCollide = false;
            // also reset the game
            cg.resetGame();
            // then just reset the game with new level
            if (cg.getLevel() <= 2) {
                cg.levelUp();
            }
            else {
                cout << "\n---------FINISH ALL LEVEL----------\n";
                cout << "\n----------CONGRATULATIONS----------\n";
                break;
            }
        }
        Sleep(100);
    }
}



int main() {


    int temp;
    fixConsoleWindow();
    //cout << "Type something and enter to start\n";
    //cin.get();
    cg.startGame();

    thread t1(SubThread);

    cout << "\n\n\n Use WASD to move your character\n";
    while (1) {

        temp = toupper(_getch());
        
        if (!cg.getPeople().getIsDead()) {
            if (temp == 27) {   // Esc = Exit
                cg.exitGame(t1.native_handle());
                return 0;
            }
            else if (temp == 'P') { // pause game
                IS_RUNNING = false;
                cg.pauseGame(t1.native_handle());
            }
            else {  // continue / resume
                IS_RUNNING = true;
                cg.resumeGame((HANDLE)t1.native_handle());
                MOVING = temp;
            }
        }
        else {
            if (temp == 'Y') {
                cg.startGame();
            }
            else {
                cg.exitGame(t1.native_handle());
                return 0;
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
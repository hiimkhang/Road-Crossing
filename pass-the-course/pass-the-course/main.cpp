
#include <iostream>
#include <Windows.h>
#include <thread>
#include <conio.h>
#include "CGame.h"
#include "console.h"
#include "Obstacle.h"
#include "Figure.h"
#include "Menu.h"
#include <string>
#include <fstream>
using namespace std;

char MOVING;
bool IS_RUNNING = true;
bool IN_GAME = true;
CGame cg;

auto t_start = std::chrono::high_resolution_clock::now();

void SubThread() {
    int i = 15;
    while (IS_RUNNING) {
        i--;
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
            system("cls");
            cout << "\n------------OH NO-------------\n";
            cout << "\n------------YOU LOSE-----------\n";
            // collide animation
            cout << "Do you want to new game with the same level?\n";
            cout << "Enter Y(Yes) or other to return to menu\n";
            char temp;
            temp = _getch();
            if (toupper(temp) == 'Y') {
                cg.resetGame();
                cg.resetLevel();
                system("cls");
                t_start = std::chrono::high_resolution_clock::now();
                cg.startGame();
            }
            else {
                //system("cls");
                cg.getPeople().setIsDead(true);
                IS_RUNNING = false;
            }
            
        }

        if (cg.isFinish()) {
            cout << "\n------------YOU WIN-------------\n";
            cout << "\n------------NEW LEVEL-----------\n";
            Sleep(400);
            // we reset the human state (curX, curY = 0), isFinish = false, isCollide = false;
            // also reset the game
            cg.resetGame();
            cg.startGame();
            // then just reset the game with new level
            if (cg.getLevel() <= 2) {
                cg.levelUp();
            }
            else {
                cout << "\n---------FINISH ALL LEVEL----------\n";
                cout << "\n----------CONGRATULATIONS----------\n";
                IS_RUNNING = false;
            }
        }
        Sleep(100);
    }
}


//int main() {
//    resizeConsole(1000, 700);
//    fixConsoleWindow();
//    Menu m;
//    try {
//        //// Display win logo
//        //for (int i = 0; i < 15; ++i) {
//        //    ShowConsoleCursor(0);
//        //    clrscr();
//        //    m.logoLose();
//        //    Sleep(100);
//        //}
//        //while (_kbhit())
//        //    _getch();
//        //Textcolor(White);
//        //gotoxy(54, 30);		cout << " PRESS ANY KEY TO CONTINUE... ";
//        //Textcolor(15);
//        //_getch();
//
//
//        //// Display menu
//        //m.menu();
//       
//    }
//    catch (string s) {
//        cout << "Error: " + s;
//    }
//
//    cout << endl;
//    return 0;
//}

////Dang
//int main()
//{
//    Menu m;
//    m.loadGame();
//    
//}


 //Tri
 
int main() {
    int temp;
    resizeConsole(1000, 700);
    fixConsoleWindow();

    while (IN_GAME) {
        Menu m;
        string lg;
        lg = m.menu();
        //cout << "Type something and enter to start\n";
        //cin.get();
        
        if (lg != "")
            cg.loadGame(lg);
        t_start = std::chrono::high_resolution_clock::now();
        cg.startGame();
        IS_RUNNING = true;
        thread t1(SubThread);
        int i = 0;
        //cout << "\n\n\n Use WASD to move your character\n";
        while (1) {
            ++i;
            temp = toupper(_getch());
            //!cg.getPeople().getIsDead()
            if (IS_RUNNING) {
                if (temp == 27) {   // Esc = Exit
                    cg.exitThread(&t1, IS_RUNNING);
                    return 0;
                }
                else if (temp == 'P') { // pause game
                    // pause menu
                    // save game
                    // on off sound
                    // exit
                    
                    cg.pauseGame(t1.native_handle());
                    cg.saveGame("new3.dat");
                }
                else if (temp == 'T') { // load game
                    // ask user to enter the file dir have been save to load game from it
                    cg.pauseGame(t1.native_handle());
                    system("cls");
                    string dir = "";
                    dir = m.loadGame();
                    if (dir != "") {
                        cg.loadGame(dir);
                        t_start = std::chrono::high_resolution_clock::now();
                        cg.startGame();
                    }
                    system("cls");
                    cg.drawGame();
                    cg.resumeGame((HANDLE)t1.native_handle());
                }
                else if (temp == 'L') { // save game
                    // ask user to enter file dir to save game
                    // ask them want to continue or not
                    cg.pauseGame(t1.native_handle());
                    system("cls");
                    string dir = "";
                    cout << "Enter name of file\n";
                    getline(cin, dir);
                    cg.saveGame(dir + ".dat");
                    Sleep(400);
                    system("cls");
                    cg.drawGame();
                    cg.resumeGame((HANDLE)t1.native_handle());
                }
                else {  // continue / resume
                    IS_RUNNING = true;
                    cg.resumeGame((HANDLE)t1.native_handle());
                    MOVING = temp;
                }

            }
            else {
                system("cls");
                //cg.exitGame(t1.native_handle());
                cg.exitThread(&t1, IS_RUNNING);
                IS_RUNNING = false;
                cg.resetGame();
                cg.resetLevel();
                break;
            }

        }
        //t1.join();
    }
    
    return 0;
}


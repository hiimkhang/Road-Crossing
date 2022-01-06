
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
bool IN_THREAD = true;
bool soundON = true;

CGame cg;

auto t_start = std::chrono::high_resolution_clock::now();
auto t_start2 = std::chrono::high_resolution_clock::now();

void SubThread() {
    int i = 15;
    while (IS_RUNNING) {
        i--;
        if (IN_THREAD) {
            auto t_now = std::chrono::high_resolution_clock::now();
            double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_now - t_start).count();
            double elapsed_time_ms2 = std::chrono::duration<double, std::milli>(t_now - t_start2).count();
            if (elapsed_time_ms > 3000) {   // every 3 second light will change
                t_start = t_now;
                //cout << "elapsed_time_ms: " << elapsed_time_ms << endl;
                cg.updateRedLightEven();
            }
            if (elapsed_time_ms2 > 2000) {   // every 2 second light will change
                t_start2 = t_now;
                //cout << "elapsed_time_ms: " << elapsed_time_ms << endl;
                cg.updateRedLightOdd();
            }

            if (!cg.getPeople().getIsDead()) {
                cg.updatePosPeople(MOVING, soundON);     // take the input form user -> assign to MOVING = temp -> update position
            }
            MOVING = ' ';                       // reset the moving, stop the human, if user dont input -> the humam still stop
            cg.updatePosCLane();                // update the position of each obstacle in the list (move the clane)

            //cg.drawLane(8);                    // draw ?

            if (cg.isCollided()) {              // human collide with obstacle
                cg.explode(soundON);
                Textcolor(0);

                // this for loop is to solve the red screen error after cg.explode();
                for (int i = 0; i <= 36; ++i)
                    cout << "                                                                                               ";

                IN_THREAD = false;
                clrscr();

                Menu::printLose();
                //Menu m;
                //m.loadingScreen();
                //int x = 40;
                //int y = 15;

                //gotoxy(x + 9, y + 1); cout << "------------OH NO---------------";
                //gotoxy(x + 9, y + 3); cout << "------------YOU LOSE------------";
                //// collide animation
                //gotoxy(x + 9, y + 7); cout << "Do you want to new game with the same level?";
                //gotoxy(x + 9, y + 9); cout << "Enter Y(Yes) or other to return to menu";
                /*cg.getPeople().setIsDead(true);
                cout << "deeeeeeeeeeeee" << cg.getPeople().getIsDead();*/
                //char temp = toupper(_getch()); // can not use getch here, because the getch in main always call first, so just hanlde value pass in getch in main
            }

            if (cg.isFinish()) {
                int x = 54;
                int y = 22;

               /* gotoxy(x + 9, y + 1); cout << "------------YOU WIN-------------";
                gotoxy(x + 9, y + 3); cout << "------------NEW LEVEL-----------";*/
                /*Menu::levelTransfer();*/

                Sleep(1000);
                // we reset the human state (curX, curY = 0), isFinish = false, isCollide = false;
                // also reset the game
                
                // then just reset the game with new level
                if (cg.getLevel() <= 3) {
                    cg.resetGame();
                    cg.levelUp();
                    cg.levelTransfer();
                    cg.startGame();               
                }
                else {
                    Menu::printWin();
                    Menu m;
                    m.loadingScreen();
                    break;

                    //gotoxy(x + 9, y + 1); cout << "---------FINISH ALL LEVEL----------";
                    //gotoxy(x + 9, y + 3); cout << "----------CONGRATULATIONS----------";
                    //IN_THREAD = false;
                    //clrscr();
                    //// win animation
                    //Sleep(400);
                    //clrscr();
                    //gotoxy(x + 9, y + 3);
                    //cout << "Press any key to return to menu\n";
                }
            }
            Sleep(100);
        }
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

//Dang
//int main()
//{
//    Figure f(".//Figure/Obstacle//devil.txt");
//    f.print(50, 10);
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
        /*m.loadingScreen();*/
        soundON = m.getSound();

        //cout << "Type something and enter to start\n";
        //cin.get();
        
        if (lg != "")
            cg.loadGame(lg);
        else {
            cg.resetGame();
            cg.resetHumanStat();
            cg.resetLevel();
        }
        t_start = std::chrono::high_resolution_clock::now();
        t_start2 = std::chrono::high_resolution_clock::now();
        cg.startGame();
        Sleep(200);
        IS_RUNNING = true;
        thread t1(SubThread);
        int i = 0;
        //cout << "\n\n\n Use WASD to move your character\n";
        while (1) {
            ++i;
            temp = toupper(_getch());
            if (cg.isFinish() && cg.getLevel() >= 4) {
                
                //cg.exitGame(t1.native_handle());
                cg.exitThread(&t1, IS_RUNNING);
                IS_RUNNING = false;
                IN_THREAD = true;
                break;
            }
            if (!cg.getPeople().getIsDead()) {

                if (temp == 27) {   // Esc = Exit
                    /*cg.exitThread(&t1, IS_RUNNING);*/
                    cg.exitThread(&t1, IS_RUNNING);
                    IS_RUNNING = false;
                    IN_THREAD = true;
                    break;
                }
                else if (temp == 'P' ) { // pause game
                    // pause menu
                    // save game
                    // on off sound
                    // exit

                    cg.pauseGame(t1.native_handle());
                    m.subMenu(cg);
                    cg.drawGame();
                    cg.resumeGame((HANDLE)t1.native_handle());

                    //cg.saveGame("new3.dat");
                }
                else if (temp == 'T') { // load game
                    // ask user to enter the file dir have been save to load game from it
                    cg.pauseGame(t1.native_handle());
                    clrscr();


                    string dir = "";
                    dir = m.loadGame(1);
                    if (dir != "") {
                        if (cg.loadGame(dir)) {
                            t_start = std::chrono::high_resolution_clock::now();
                            t_start2 = std::chrono::high_resolution_clock::now();
                        }
                        else {
                            cg.resetGame();
                        }
                    }
                    //Sleep(1000);
                    clrscr();
                    cg.drawGame();
                    cg.resumeGame((HANDLE)t1.native_handle());
                }
                else if (temp == 'L') { // save game
                    // ask user to enter file dir to save game
                    // ask them want to continue or not
                    cg.pauseGame(t1.native_handle());
                    clrscr();
                    string dir = "";
                    int x = 38;
                    int y = 17;

                    Textcolor(DarkYellow);
                    gotoxy(x + 5, y + 9);
                    cout << "Example: save1";
                    gotoxy(x + 3, y + 7);
                    cout << (char)175 << " The directory will become: Save/save1.dat";

                    Textcolor(8);
                    gotoxy(x, y);
                    for (int i = 0; i < 50; ++i)
                        cout << UP_BLACK_PIECE;

                    gotoxy(x, y + 2);
                    for (int i = 0; i < 50; ++i)
                        cout << DOWN_BLACK_PIECE;

                    for (int i = 0; i < 3; ++i) {
                        gotoxy(x - 1, y + i);
                        cout << VERTICAL_BLACK_PIECE;
                    }
                    for (int i = 0; i < 3; ++i) {
                        gotoxy(x + 50, y + i);
                        cout << VERTICAL_BLACK_PIECE;
                    }

                    gotoxy(x - 1, y - 2); cout << "Enter name of file to save";
                    gotoxy(x + 2, y + 1);
                    getline(cin, dir);
                    cg.saveGame(dir + ".dat");
                    gotoxy(x + 14, y + 5); cout << "Saving...";
                    Sleep(2000);
                    clrscr();
                    cg.drawGame();
                    cg.resumeGame((HANDLE)t1.native_handle());
                }
                else if (temp == 'M') {
                    soundON = !soundON;
                }
                else {  // continue / resume
                    IS_RUNNING = true;
                    cg.resumeGame((HANDLE)t1.native_handle());
                    MOVING = temp;
                }
            }
            else {
                if (temp == 'Y') {
                    cg.pauseGame(t1.native_handle());
                    Textcolor(DarkYellow);
                    gotoxy(49, 33);
                    cout << "Continue where you have dead...\n";
                    Sleep(2000);
                    cg.resetHumanStat();
                    cg.resetGame();
                    cg.setupLevel();
                    clrscr();
                    t_start = std::chrono::high_resolution_clock::now();
                    t_start2 = std::chrono::high_resolution_clock::now();
                    cg.startGame();
                    cg.resumeGame((HANDLE)t1.native_handle());
                }
                else {
                    clrscr();
                    //cg.exitGame(t1.native_handle());
                    cg.exitThread(&t1, IS_RUNNING);
                    IS_RUNNING = false;
                    IN_THREAD = true;
                    break;
                }
            }
            IN_THREAD = true;
        }
        //t1.join();
    }
    
    return 0;
}



#ifndef _MENU_H
#define _MENU_H

#include "console.h"
#include "CGame.h"
#include <fstream>
#include <string>
#include <filesystem>


class Menu {
private:
    int mode = 0; // 0: easy, 1: hard
    bool soundStatus = 1; // 0: off, 1: on
    bool isLoad = 0;
    bool isSave = 0;

    bool outMenu = 1;

public:
    string menu();
    void setting();
    string loadGame();

    // clear Menu instead of clear screen, for optimizing
    void clearMenu();

    void logoMenu();
    void logoWin();
    void logoLose();

    void loadingScreen();

    void subMenu(CGame& cg);
};

#endif
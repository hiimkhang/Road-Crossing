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
    bool isSubMenu = 0;

public:
    string menu();
    void setting();
    string loadGame();

    // clear Menu instead of clear screen, for optimizing
    void clearMenu();

    void logoMenu();
    static void logoWin();
    static void logoLose();
    static void levelLogo(int x, int y, int color);
    static void levelupLogo(int x, int y, int color);
    static void oneLogo(int x, int y, int color);
    static void twoLogo(int x, int y, int color);
    static void threeLogo(int x, int y, int color);
    static void fourLogo(int x, int y, int color);
    static void HP(int x, int y, int color);
    static void info(CGame& cg);

    void loadingScreen();

    void subMenu(CGame& cg);
};

#endif
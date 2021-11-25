#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "console.h"

class Obstacle {
private:
    int curX, curY;
    int prevX, prevY;
    // hitbox size
    int sizeX, sizeY;

public:
    Obstacle() : 
        curX(0), curY(0),
        prevX(0), prevY(0),
        sizeX(0), sizeY(0) {}
    
    Obstacle(int x, int y) :
        curX(x), curY(y),
        prevX(0), prevY(0),
        sizeX(0), sizeY(0) {}
    
    Obstacle(int curX, int curY, int prevX, int prevY, 
    int sizeX, int sizeY) :
        curX(curX), curY(curY),
        prevX(prevX), prevY(prevY),
        sizeX(sizeX), sizeY(sizeY) {}
    
    virtual void move(int speedX, int speedY) {
        prevX = curX, prevY = curY;
        curX += speedX;
        curY += speedY;
    }

    int getCurX() { return curX;}
    int getCurY() { return curY;}
    void setXY(int x, int y) { 
        prevX = curX, prevY = curY;
        curX = x; curY = y;
    }

    int getSizeX() { return sizeX;}
    int getSizeY() { return sizeY;}
    void setSize(int x, int y) {
        sizeX = x, sizeY = y;
    }

    // ? idk 
    virtual void collisonSound() = 0;  
    virtual void print() = 0;
};

class Rock : public Obstacle {
public:
    Rock() : Obstacle() {
        setSize(3, 1);
    }

    // Init location
    Rock(int x, int y) : Obstacle(x, y) {
        setSize(3, 1);
    }
    
    // Override 
    void move(int speedX, int speedY) {}
    
    void print() {
        int x = getCurX(), y = getCurY();

        for (int i = 0; i < getSizeX(); ++i) {
            Textcolor(8);
            gotoxy(x + i, y);
            cout << char(219);
        }
        Textcolor(7);
    }

    void collisonSound() {
        // Ae kiếm sound bỏ vào chứ mình chịu                  
    }
};

class Cop : public Obstacle {
public:
    Cop() : Obstacle() {
        setSize(5, 5);
    }

    // Init location
    Cop(int x, int y) : Obstacle(x, y) {
        setSize(5, 5);
    }
    
    // Override 
    void move(int speedX, int speedY) {
        int initX = getCurX();
        int initY = getCurY();
        int i = 0;

        while (i < 20) {
            if (getCurX() > initX + 10) {
                while (getCurX() > initX) {
                    unPrint();
                    setXY(getCurX() - speedX, getCurY() - speedY);
                    print();
                    Sleep(100);
                    ++i;
                }
            }
            else {
                unPrint();
                setXY(getCurX() + speedX, getCurY() + speedY);
                print();
                Sleep(100);
                ++i;
            }
        }
    }

    void print() {
        int x = getCurX(), y = getCurY();

        // Head
        Textcolor(Yellow);
        gotoxy(x + 2, y);
        cout << char(203);
        Textcolor(White);
        gotoxy(x + 2, y + 1);
        cout << char(223);

        // Body
        Textcolor(DarkYellow);
        gotoxy(x, y + 2);
        cout << char(222);
        Textcolor(Yellow);  
        gotoxy(x + 1, y + 2); 
        cout << char(222);
        gotoxy(x + 2, y + 2); 
        cout << char(219);
        gotoxy(x + 3, y + 2); 
        cout << char(221);
        Textcolor(DarkYellow);
        gotoxy(x + 4, y + 2);
        cout << char(221);

        // Legs
        gotoxy(x + 1, y + 3); 
        cout << char(222);
        gotoxy(x + 3, y + 3); 
        cout << char(221);
        Textcolor(White);
        gotoxy(x + 1, y + 4); 
        cout << char(188);
        gotoxy(x + 3, y + 4); 
        cout << char(200);
 
        Textcolor(7);
    }

    void unPrint() {
        int x = getCurX(), y = getCurY();

        for (int i = 0; i < 5; ++i) {
            gotoxy(x, y + i);
            cout << "     ";
        }
    }

    void collisonSound() {
        // Ae kiếm sound bỏ vào chứ mình chịu                  
    }
};

class Potion : public Obstacle {
public:
    Potion() : Obstacle() {
        setSize(3, 1);
    }

    // Init location
    Potion(int x, int y) : Obstacle(x, y) {
        setSize(3, 1);
    }
    
    // Override 
    void move(int speedX, int speedY) {}

    void print() {
        int x = getCurX(), y = getCurY();

        for (int i = 0; i < getSizeX(); ++i) {
            Textcolor(Red);
            gotoxy(x + i, y);
            cout << char(3);
        }
        Textcolor(7);
    }

    void collisonSound() {
        // Ae kiếm sound bỏ vào chứ mình chịu                  
    }
};

#endif
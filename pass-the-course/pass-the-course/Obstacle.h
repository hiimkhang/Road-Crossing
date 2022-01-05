#ifndef _OBSTACLE_H
#define _OBSTACLE_H

#include "console.h"
#include "Figure.h"

const int MAX_WIDTH = 82;

class Obstacle {
protected:
    int curX, curY;
    int prevX, prevY;
    // hitbox size
    int sizeX, sizeY;
    Figure fig;
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
    string getFigDir() { return fig.getDir(); }
    void setFigDig(string dir) { fig.setDir(dir); }
    int getSizeX() { return sizeX;}
    int getSizeY() { return sizeY;}
    void setSize(int x, int y) {
        sizeX = x, sizeY = y;
    }

    // ? idk 
    virtual int getID()
    {
        return 0;
    }
    virtual void collisonSound() = 0;  
    virtual void print() = 0;
    virtual void unPrint() = 0;
    
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
    int getID()
    {
        return 1;
    }
    void print() {
        int x = getCurX(), y = getCurY();

        for (int i = 0; i < getSizeX(); ++i) {
            Textcolor(8);
            gotoxy(x + i, y);
            cout << char(219);
        }
        Textcolor(7);
    }
    void unPrint()
    {

    }
    void collisonSound() {
        // Ae kiếm sound bỏ vào chứ mình chịu                  
    }
};

class Cop : public Obstacle {
private:
    //Figure fig = Figure(".//Figure//Obstacle//cop.txt");
    
    // Figure* fig;

public:
    Cop() : Obstacle() {
        fig.setDir(".//Figure/Obstacle//cop.txt");
        setSize(5, 5);
    }

    // Init location
    Cop(int x, int y) : Obstacle(x, y) {
        fig.setDir(".//Figure/Obstacle//cop.txt");
        setSize(5, 5);
    }
    
    // Override 
    void move(int speedX, int speedY) {
        prevX = curX;
        prevY = curY;
        curX += speedX;
        curY += speedY;
        if (speedX >= 0) {
            if (curX >= MAX_WIDTH)
                curX = 6;
        }
        else {
            if (curX <= 6)
                curX = MAX_WIDTH -1;
        }
        
        /*int initX = getCurX();
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
        }*/
    }
    int getID()
    {
        return 2;
    }
    void print() {
        int x = getCurX(), y = getCurY();
        ShowConsoleCursor(false);
        fig.print(x, y);
        // // Head
        // Textcolor(Yellow);
        // gotoxy(x + 2, y);
        // cout << char(203);
        // Textcolor(White);
        // gotoxy(x + 2, y + 1);
        // cout << char(223);

        // //// Body
        // Textcolor(DarkYellow);
        // gotoxy(x, y + 2);
        // cout << char(222);
        // Textcolor(Yellow);  
        // gotoxy(x + 1, y + 2); 
        // cout << char(222);
        // gotoxy(x + 2, y + 2); 
        // cout << char(219);
        // gotoxy(x + 3, y + 2); 
        // cout << char(221);
        // Textcolor(DarkYellow);
        // gotoxy(x + 4, y + 2);
        // cout << char(221);

        // //// Legs
        // gotoxy(x + 1, y + 3); 
        // cout << char(222);
        // gotoxy(x + 3, y + 3); 
        // cout << char(221);
        // Textcolor(White);
        // gotoxy(x + 1, y + 4); 
        // cout << char(188);
        // gotoxy(x + 3, y + 4); 
        // cout << char(200);
 
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
private:
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
    int getID()
    {
        return 3;
    }
    void print() {
        int x = getCurX(), y = getCurY();

        for (int i = 0; i < getSizeX(); ++i) {
            Textcolor(Red);
            gotoxy(x + i, y);
            cout << char(3);
        }
        Textcolor(7);
    }
    void unPrint()
    {

    }
    void collisonSound() {
        // Ae kiếm sound bỏ vào chứ mình chịu                  
    }
};


class WSpider : public Obstacle {
private:
public:
    WSpider() : Obstacle() {
        fig.setDir(".//Figure/Obstacle//spider-white.txt");
        setSize(5, 5);
    }

    // Init location
    WSpider(int x, int y) : Obstacle(x, y) {
        fig.setDir(".//Figure/Obstacle//spider-white.txt");
        setSize(5, 5);
    }

    // Override 
    void move(int speedX, int speedY) {
        prevX = curX;
        prevY = curY;
        curX += speedX;
        curY += speedY;
        if (speedX >= 0) {
            if (curX >= MAX_WIDTH)
                curX = 6;
        }
        else {
            if (curX <= 6)
                curX = MAX_WIDTH - 1;
        }

        
    }
    int getID()
    {
        return 4;
    }
    void print() {
        int x = getCurX(), y = getCurY();
        ShowConsoleCursor(false);
        fig.print(x, y);

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


class Devil : public Obstacle {
private:
public:
    Devil() : Obstacle() {
        fig.setDir(".//Figure/Obstacle//devil.txt");
        setSize(5, 5);
    }

    // Init location
    Devil (int x, int y) : Obstacle(x, y) {
        fig.setDir(".//Figure/Obstacle//devil.txt");
        setSize(5, 5);
    }

    // Override 
    void move(int speedX, int speedY) {
        prevX = curX;
        prevY = curY;
        curX += speedX;
        curY += speedY;
        if (speedX >= 0) {
            if (curX >= MAX_WIDTH)
                curX = 6;
        }
        else {
            if (curX <= 6)
                curX = MAX_WIDTH - 1;
        }


    }
    int getID()
    {
        return 5;
    }
    void print() {
        int x = getCurX(), y = getCurY();
        ShowConsoleCursor(false);
        fig.print(x, y);

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



#endif
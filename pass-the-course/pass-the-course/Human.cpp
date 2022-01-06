#include "Human.h"

Human::Human(int x, int y) : isDead(false), life(1)
{
    //fig = Figure(".//Figure//Human//human-test.txt");
    fig = Figure(".//Figure//Human//player.txt");
    curX = x;
    curY = y;
}

void Human::moveUp()
{
    if (curY >= 3) {
        preX = curX;
        preY = curY;
        curY -= 2;
    }
}

void Human::moveDown()
{
    if (curY <= 32) {
        preX = curX;
        preY = curY;
        curY += 2;
    }
}

void Human::moveLeft()
{
    if (curX >= 7) {
        preX = curX;
        preY = curY;
        curX -= 2;
    }
}

void Human::moveRight()
{
    if (curX <= 83) {
        preX = curX;
        preY = curY;
        curX += 2;
    }
}

void Human::move()
{
    fig.deleteFootprint(preX, preY);
    fig.print(curX, curY);
}
void Human::resetFig()
{
    fig.deleteFootprint(preX, preY);
    fig.deleteFootprint(preX - 2, preY - 2);
    fig.deleteFootprint(preX + 2, preY - 2);
    fig.deleteFootprint(preX + 2, preY + 1);
    fig.deleteFootprint(preX - 2, preY + 1);
    fig.print(curX, curY);
}
void Human::initial()
{
    fig.print(curX, curY);
}

bool Human::isCollided(Obstacle* pObs) {
    int tempX = curX;
    int tempY = curY;
    if (tempX >= pObs->getCurX() && tempX <= (pObs->getCurX() + 4)    //  top left corner
        && tempY >= pObs->getCurY() && tempY <= (pObs->getCurY() + 4)) {
        return true;
    }

    tempX += width;
    if (tempX >= pObs->getCurX() && tempX <= (pObs->getCurX() + 4)    //  top right corner
        && tempY >= pObs->getCurY() && tempY <= (pObs->getCurY() + 4)) {
        return true;
    }

    tempX -= width;
    tempY += height;
    if (tempX >= pObs->getCurX() && tempX <= (pObs->getCurX() + 4)    //  bottom left corner
        && tempY >= pObs->getCurY() && tempY <= (pObs->getCurY() + 4)) {
        return true;
    }

    tempX += width;
    if (tempX >= pObs->getCurX() && tempX <= (pObs->getCurX() + 4)    //  bottom right corner
        && tempY >= pObs->getCurY() && tempY <= (pObs->getCurY() + 4)) {
        return true;
    }
    return false;
}

bool Human::getIsDead() {
    return isDead;
}
void Human::setIsDead(bool nIsDead) {
    isDead = nIsDead;
}
bool Human::isFinish() {
    if (curY <= 3) {
        return true;
    } 
    return false;
}

string Human::getFigDir()
{
    return fig.getDir();
}

int* Human::getHumanPosition()
{
    int* res = new int[2];
    *res = curX;
    *(res + 1) = curY;
    return res;
}

void Human::setHumanPosition(int* cur)
{
    curX = *(cur);
    curY = *(cur + 1);
}

void Human::reset() {
    isDead = false;
    life = 3;
    curX = 36;
    curY = 33;
    --preY;
}

void Human::setFigDir(string dir)
{
    fig.setDir(dir);
}

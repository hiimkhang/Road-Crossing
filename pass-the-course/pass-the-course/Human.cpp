#include "Human.h"

Human::Human(int x, int y) : isDead(false)
{
    //fig = Figure(".//Figure//Human//human-test.txt");
    fig = Figure(".//Figure//Human//player.txt");
    curX = x;
    curY = y;
}

void Human::moveUp()
{
    preX = curX;
    preY = curY;
    curY -= 2;
}

void Human::moveDown()
{
    preX = curX;
    preY = curY;
    curY += 2;
}

void Human::moveLeft()
{
    preX = curX;
    preY = curY;
    curX -= 2;
}

void Human::moveRight()
{
    preX = curX;
    preY = curY;
    curX += 2;
}

void Human::move()
{
    fig.deleteFootprint(preX, preY);
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
    if (curY <= 0) {
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
    curX = 32;
    curY = 24;
    --preY;
}

void Human::setFigDir(string dir)
{
    fig.setDir(dir);
}

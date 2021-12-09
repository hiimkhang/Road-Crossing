#include "Human.h"

Human::Human(int x, int y) : isDead(false)
{
    fig = Figure(".//Figure//Human//human-test.txt");
    curX = x;
    curY = y;
}

void Human::moveUp()
{
    preX = curX;
    preY = curY;
    curY -= 1;
}

void Human::moveDown()
{
    preX = curX;
    preY = curY;
    curY += 1;
}

void Human::moveLeft()
{
    preX = curX;
    preY = curY;
    curX -= 1;
}

void Human::moveRight()
{
    preX = curX;
    preY = curY;
    curX += 1;
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

    tempX += 4;
    if (tempX >= pObs->getCurX() && tempX <= (pObs->getCurX() + 4)    //  top right corner
        && tempY >= pObs->getCurY() && tempY <= (pObs->getCurY() + 4)) {
        return true;
    }

    tempX -= 4;
    tempY += 4;
    if (tempX >= pObs->getCurX() && tempX <= (pObs->getCurX() + 4)    //  bottom left corner
        && tempY >= pObs->getCurY() && tempY <= (pObs->getCurY() + 4)) {
        return true;
    }

    tempX += 4;
    if (tempX >= pObs->getCurX() && tempX <= (pObs->getCurX() + 4)    //  bottom right corner
        && tempY >= pObs->getCurY() && tempY <= (pObs->getCurY() + 4)) {
        return true;
    }
    return false;
}

bool Human::getIsDead() {
    return isDead;
}
bool Human::isFinish() {
    if (curY <= 0) {
        return true;
    } 
    return false;
}
void Human::reset() {

    isDead = false;
    curX = 20;
    curY = 20;
    --preY;
}

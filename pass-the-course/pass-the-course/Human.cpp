#include "Human.h"

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
}

void Human::initial()
{
       
}
bool Human::getIsDead() {
    return isDead;
}
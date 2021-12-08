#include "Human.h"

Human::Human()
{
    fig = Figure(".//Figure//Human//human-test.txt");
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
<<<<<<< HEAD

=======
bool Human::getIsDead() {
    return isDead;
}
>>>>>>> a23cae8940b7d4a70fa5f70be8ab4a301691d9f9

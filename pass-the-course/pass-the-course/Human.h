#ifndef _human_h_
#define _human_h_
#include "console.h"
#include "Obstacle.h"
#include "Figure.h"
const int width = 5;
const int height = 5;
class Human
{
private:
	int curX, curY, preX = -1, preY = -1;
	bool isDead;
	Figure fig;
public:
	Human(int x = 0, int y = 0);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	virtual void move();
	virtual void resetFig();
	virtual void initial();
	bool getIsDead();
	void setIsDead(bool nIsDead);
	bool isCollided(Obstacle*);
	bool isFinish();
	string getFigDir();
	int* getHumanPosition();
	int X() { return curX; }
	int Y() { return curY; }
	void setHumanPosition(int* cur);
	void reset();
	void setFigDir(string dir);

	int life;
};
#endif

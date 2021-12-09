#ifndef _human_h_
#define _human_h_
#include "console.h"
#include "Obstacle.h"
#include "Figure.h"
class Human
{
private:
	int curX, curY, preX = -1, preY = -1, life;
	bool isDead;
	Figure fig;
public:
	Human(int x = 0, int y = 0);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	virtual void move();
	virtual void initial();
	bool getIsDead();
	bool isCollided(Obstacle*);
	bool isFinish();
	void reset();
};
#endif

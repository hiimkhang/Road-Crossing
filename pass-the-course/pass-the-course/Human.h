#ifndef _human_h_
#define _human_h_
#include "console.h"
class Human
{
private:
	int curX, curY, preX = -1, preY = -1, life;
	bool isDead;
public:
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	virtual void move();
	virtual void initial();
};
#endif

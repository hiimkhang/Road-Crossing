#ifndef _cLane_h_
#define _cLane_h_
#include "Obstacle.h"
#include <vector>
#include <thread>
class CLane
{
private:
	std::vector<Obstacle*> list;
	bool redLight;
	int speedX;
	int curY;
public:
	vector<Obstacle*>& getListObstacle();
	bool getRedLight();
	int getSpeedX();
	int getCurY();
	void move();
	void updateSpeed(int newSpeed);
	void changeLight();
	void print();
	void add(Obstacle* ob);
	void set(int y, int x, bool rl);
	CLane(int id = 2, int numOfCop = 0, int newY = 0);
	~CLane();
};

#endif // !_cLane_h_

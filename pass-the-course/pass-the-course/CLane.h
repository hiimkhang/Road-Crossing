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
public:
	void move();
	CLane();
};

#endif // !_cLane_h_

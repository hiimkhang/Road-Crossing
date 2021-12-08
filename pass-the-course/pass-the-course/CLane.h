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
	void move();	// ham move t nghi them tham so int, de cho cai cung lane move voi toc do tuy y
	// them ham add obstacle vo list nua Dang
	CLane(int numOfCop = 1, int newY = 0);
};

#endif // !_cLane_h_

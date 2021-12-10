#include "CLane.h"

CLane::CLane(int numOfCop, int newY) : speedX(1), curY(newY), redLight(false)
{
	Obstacle* temp1 = nullptr;
	for (int i = 1; i <= numOfCop; ++i) {
		temp1 = new Cop(i*14, curY);
		temp1->print();
		list.push_back(temp1);
	}
}

vector<Obstacle*>& CLane::getListObstacle() {
	return list;
}
bool CLane::getRedLight() {
	return redLight;
}

void CLane::move()
{
	for (auto& obs : list)
	{
		obs->unPrint();
		obs->move(speedX, 0);
		obs->print();
	}
}

void CLane::updateSpeed(int newSpeed) {
	speedX = newSpeed;
}
void CLane::changeLight() {
	redLight = !redLight;
}

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
CLane::~CLane() {
	for (auto& obs : list)
	{
		delete obs;
	}
}
vector<Obstacle*>& CLane::getListObstacle() {
	return list;
}
bool CLane::getRedLight() {
	return redLight;
}

int CLane::getSpeedX()
{
	return speedX;
}

int CLane::getCurY()
{
	return curY;
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
void CLane::print()
{
	for (auto& obs : list)
	{
		obs->print();
	}
}
void CLane::updateSpeed(int newSpeed) {
	speedX = newSpeed;
}
void CLane::changeLight() {
	redLight = !redLight;
}

void CLane::add(Obstacle* ob)
{
	list.push_back(ob);
}

void CLane::set(int y, int x, bool rl)
{
	curY = y;
	speedX = x;
	redLight = rl;
}

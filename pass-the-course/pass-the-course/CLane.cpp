#include "CLane.h"

CLane::CLane(int id, int numOfCop, int newY) : speedX(1), curY(newY), redLight(false)
{
	Obstacle* temp1 = nullptr;
	auto it = find(list.begin(), list.end(), temp1);
	switch (id) {
		case 1: // Rock
			for (int i = 1; i <= numOfCop; ++i) {
				temp1 = new Rock(i * 13, curY);
				//temp1->print();
				list.push_back(temp1);
			}
			break;
		case 2:	// Cop
			for (int i = 1; i <= numOfCop; ++i) {
				temp1 = new Cop(i * 13, curY);
				//temp1->print();
				list.push_back(temp1);
			}
			break;
		case 3:	// Potion
			for (int i = 1; i <= numOfCop; ++i) {
				temp1 = new Potion(i * 13 + 45, curY + 1);
				//temp1->print();
				list.push_back(temp1);
			}
			
			break;
		case 4:	// WSpider
			for (int i = 1; i <= numOfCop; ++i) {
				temp1 = new WSpider(i * 13, curY);
				//temp1->print();
				list.push_back(temp1);
			}
			break;
		case 5:	// Devil
			for (int i = 1; i <= numOfCop; ++i) {
				temp1 = new Devil(i * 13, curY);
				//temp1->print();
				list.push_back(temp1);
			}
			break;
		default:// Cop
			for (int i = 1; i <= numOfCop; ++i) {
				temp1 = new Cop(i * 13, curY);
				//temp1->print();
				list.push_back(temp1);
			}
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

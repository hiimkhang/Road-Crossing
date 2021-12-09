#include "CLane.h"

vector<Obstacle*>& CLane::getListObstacle() {
	return list;
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

CLane::CLane(int numOfCop, int newY) : speedX(1), curY(newY)
{
	Obstacle* temp1 = nullptr;
	for (int i = 1; i <= numOfCop; ++i) {
		temp1 = new Cop(i*12, curY);
		temp1->print();
		list.push_back(temp1);
	}
}

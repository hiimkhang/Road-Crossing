#include "CLane.h"

void CLane::move()
{
	for (auto& obs : list)
	{
		obs->move(speedX, 0);
		obs->print();
	}

}

CLane::CLane()
{
	Obstacle* temp1 = new Cop();
	list.push_back(temp1);
}

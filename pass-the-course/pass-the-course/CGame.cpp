#include "CGame.h"

CGame::CGame() :  isPause(false), isCollised(false)
{
	gotoxy(12, 10);
	cout << "Cop's speed 2: " << endl;
	Obstacle* pO = new Cop(20, 20);
	pO->print();
	listObstacle.push_back(pO);

	cout << "Rock:" << endl;
	pO = new Rock(20, 20);
	pO->print();
	listObstacle.push_back(pO);
	cout << "CGame::CGame()" << endl;
}
CGame::~CGame() {
	int n = listObstacle.size();
	for (int i = 0; i < n; ++i) {
		delete listObstacle[i];
	}
}
Human CGame::getPeople() {
	return human;
}
vector<Obstacle*>& CGame::getListObstacle() {
	return listObstacle;
}

void CGame::startGame() {
	int n = listObstacle.size();
	for (int i = 0; i < n; ++i) {
		listObstacle[i]->move(2, 0);
	}
}
void CGame::updatePosObstacle() {

}
void CGame::drawGame() {

}
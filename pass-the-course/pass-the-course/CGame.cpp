#include "CGame.h"

CGame::CGame() :  isPause(false), isCollised(false)
{
	// old version

	/*Obstacle* pO;
	gotoxy(12, 10);
	cout << "1.Cop's speed 2: " << endl;
	pO = new Cop(12, 10);
	pO->print();
	listObstacle.push_back(pO);

	gotoxy(12, 18);
	cout << "2.Cop's speed 2: " << endl;
	pO = new Cop(32, 10);
	pO->print();
	listObstacle.push_back(pO);*/

	/*cout << "Rock:" << endl;
	pO = new Rock(20, 20);
	pO->print();
	listObstacle.push_back(pO);*/

	// new version with clane
	CLane* pC = new CLane(1,0);
	listCLane.push_back(pC);
	pC = new CLane(2,8);
	listCLane.push_back(pC);
	cout << endl << "CGame::CGame()" << endl;
}
CGame::~CGame() {
	int n = listCLane.size();
	for (int i = 0; i < n; ++i) {
		delete listCLane[i];
	}
}
Human CGame::getPeople() {
	return human;
}
vector<CLane*>& CGame::getListCLane() {
	return listCLane;
}

void CGame::startGame() {
	// show the start intro, if this the first time play
	// else quick screen like "game start" then the game run
	/*int n = listObstacle.size();
	for (int i = 0; i < n; ++i) {
		listObstacle[i]->unPrint();
		listObstacle[i]->move(2, 0);
		listObstacle[i]->print();
	}*/
	
}
void CGame::updatePosCLane() {
	for (auto& item : listCLane)
	{
		item->move();
	}
}
void CGame::drawGame() {

}
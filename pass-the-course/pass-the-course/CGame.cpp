#include "CGame.h"

CGame::CGame() :  isPause(false), isCollised(false)
{
	Obstacle* pO;
	gotoxy(12, 10);
	cout << "1.Cop's speed 2: " << endl;
	pO = new Cop(12, 10);
	pO->print();
	listObstacle.push_back(pO);

	gotoxy(12, 18);
	cout << "2.Cop's speed 2: " << endl;
	pO = new Cop(32, 10);
	pO->print();
	listObstacle.push_back(pO);



	/*cout << "Rock:" << endl;
	pO = new Rock(20, 20);
	pO->print();
	listObstacle.push_back(pO);*/
	cout << endl << "CGame::CGame()" << endl;
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
	// show the start intro, if this the first time play
	// else quick screen like "game start" then the game run
	int n = listObstacle.size();
	for (int i = 0; i < n; ++i) {
		listObstacle[i]->move(2, 0);	
	}
}
void CGame::updatePosObstacle() {

}
void CGame::drawGame() {

}
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

	// initial HUMAN

	human = Human(20, 20);
	human.initial();


	// new version with clane
	CLane* pC = new CLane(1,0);	// clane with 1 cop, y-coordinate of the lane is 0
	listCLane.push_back(pC);
	pC = new CLane(2,8);		// clane with 2 cop, y-coordinate is 8
	listCLane.push_back(pC);


	//cout << endl << "CGame::CGame()" << endl;
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
	// show the start intro, 
	// draw the box, the point life, ....
	
}
void CGame::updatePosCLane() {
	for (auto& item : listCLane)
	{
		item->move();
	}
	// anthoer method
	// use an 0 1 2D array for storing the place of obstacle
}
void CGame::drawGame() {

}
void CGame::updatePosPeople(char MOVING) {

	int x = toupper(MOVING);
	switch (x)
	{
		case 'W':
			human.moveUp();
			break;
		case 'D':
			human.moveRight();
			break;
		case 'S':
			human.moveDown();
			break;
		case 'A':
			human.moveLeft();
			break;
		default:
			return;
	}
	human.move();
}
bool CGame::isCollided() {
	// simple method, loop through all object to chek x, y with x,y of human
	for (auto& clane : listCLane) {
		vector<Obstacle*>& listObstacle = clane->getListObstacle();
		for (auto& obstacle : listObstacle) {
			if (human.isCollided(obstacle)) {
				return true;
			}
		}
	}
	return false;
}
bool CGame::isFinish() {
	if (human.isFinish()) {
		return true;
	}
	return false;
}
void CGame::resetPeople() {
	human.reset();
	human.move();
}
void CGame::levelUp() {

}
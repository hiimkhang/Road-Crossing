#include "CGame.h"

CGame::CGame(int newLevel) :  level(1), isPause(false), isCollised(false)
{
	// initial HUMAN
	human = Human(32, 24);

	level = newLevel;
	switch (level) {
		case 1:
			setupLevel1();
			break;
		case 2:
			setupLevel2();
			break;
		case 3:
			setupLevel3();
			break;
		default:
			setupLevel1();
	}


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
int CGame::getLevel() {
	return level;
}
vector<CLane*>& CGame::getListCLane() {
	return listCLane;
}

void CGame::startGame() {
	// show the start intro, 
	// draw the box, the point life, ....
	drawGame();
}
void CGame::updatePosCLane() {
	if (!isPause) {
		for (auto& item : listCLane)
		{
			item->move();
		}
	}
}
void CGame::drawGame() {
	human.initial();
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

void CGame::resetGame() {
	Sleep(200);
	system("cls");
	human.reset();
	human.move();	// return to start position

	int n = listCLane.size();
	for (int i = 0; i < n; ++i) {
		delete listCLane[i];
	}
	listCLane.clear();

}
void CGame::setupLevel1() {
	CLane* pC = new CLane(1, 0);	// clane 1 with 1 cop, y-coordinate of the lane is 0
	pC->updateSpeed(2);				// speed 2
	listCLane.push_back(pC);
	pC = new CLane(2, 8);			// clane 2 with 2 cop, y-coordinate is 8
	listCLane.push_back(pC);
	pC = new CLane(1, 16);			// clane 3 with 1 cop, y-coordinate is 16
	listCLane.push_back(pC);
}
void CGame::setupLevel2() {
	CLane* pC = new CLane(2, 0);	
	listCLane.push_back(pC);
	pC = new CLane(2, 8);		
	listCLane.push_back(pC);
	pC = new CLane(1, 16);
	listCLane.push_back(pC);
}
void CGame::setupLevel3() {
	CLane* pC = new CLane(2, 0);
	pC->updateSpeed(2);
	listCLane.push_back(pC);
	pC = new CLane(3, 8);
	listCLane.push_back(pC);
	pC = new CLane(2, 16);
	pC->updateSpeed(2);
	listCLane.push_back(pC);
}
void CGame::levelUp() {
	switch (level) {
		case 1:
			++level;
			setupLevel2();
			cout << "\n---------LEVEL 2----------\n";
			break;
		case 2:
			++level;
			setupLevel3();
			cout << "\n---------LEVEL 3----------\n";
			break;
		default:
			cout << "Out of level\n";
			_getch();
			return;
	}
}
bool CGame::isFinish() {
	if (human.isFinish()) {
		return true;
	}
	return false;
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
	// another method
	// use an 0 1 2D array for storing the place of obstacle
	return false;
}
void CGame::pauseGame(HANDLE h) {
	SuspendThread(h);
}
void CGame::resumeGame(HANDLE h) {
	ResumeThread(h);
}
void CGame::exitGame(HANDLE h) {
	TerminateThread(h, 0);
	system("cls");
	cout << "Thanks for playing the game\n";
	cout << "Good bye\n";
}
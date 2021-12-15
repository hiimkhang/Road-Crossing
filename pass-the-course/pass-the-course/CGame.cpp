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
	clockStart = std::clock();
	// show the start intro, 
	// draw the box, the point life, ....
	drawGame();
}
void CGame::drawGame() {
	human.initial();
	int n = listCLane.size();
	for (int i = 0; i < n; ++i) {
		gotoxy(69, i * 8 + 2);
		if (listCLane[i]->getRedLight()) {
			Textcolor(2);
			cout << "RED SKULL   ";
		}
		else {
			Textcolor(12);
			cout << "GREEN GOBLIN";
		}
	}
}
void CGame::updatePosCLane() {
	if (!isPause) {
		for (auto& clane : listCLane)
		{
			if(clane->getRedLight() == false)
				clane->move();
		}
	}
}
void CGame::updateRedLight() {
	int n = listCLane.size();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			listCLane[i]->changeLight();
		}
		gotoxy(69, i*8 + 2);
		if (listCLane[i]->getRedLight()) {
			Textcolor(2);
			cout << "RED SKULL   ";
		}
		else {
			Textcolor(12);
			cout << "GREEN GOBLIN";
		}
	}
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

void CGame::loadGame(string fn)
{
	ifstream in(".//Save//" + fn);
	//human
	string humanFigDir;
	in >> humanFigDir;
	human.setFigDir(humanFigDir);
	int* curHuman = new int[2];
	in >> *curHuman >> *(curHuman + 1);
	human.setHumanPosition(curHuman);
	int numOfLane;
	in >> numOfLane;
	listCLane.clear();
	for (int i = 0; i < numOfLane; i++)
	{
		CLane* lane = new CLane;
		int numOfObs;
		in >> numOfObs;
		for (int j = 0; j < numOfObs; j++)
		{
			int id; 
			in >> id;
			Obstacle* obs = nullptr;
			int tX, tY;
			in >> tX >> tY;
			switch(id)
			{
			case 1:
				obs = new Rock(tX, tY);
				break;
			case 3:
				obs = new Potion(tX, tY);
				break;
			case 2: 
				obs = new Cop(tX, tY);
				break;
			default:
				obs = new Cop(tX, tY);
				break;
			}
			lane->add(obs);
		}
		int y, x;
		bool rl;
		in >> y >> x >> rl;
		lane->set(y, x, rl);
		listCLane.push_back(lane);
	}
	int lv;
	in >> lv;
	level = level;
}

void CGame::saveGame(string fn)
{
	ofstream out(".//Save//" + fn);
	//from human
	out << human.getFigDir() << endl; //dir of figure
	int* pos = human.getHumanPosition();
	out << *(pos) << " " << *(pos + 1) << endl; //position
	out << listCLane.size() << endl;
	for (auto& lane : listCLane)
	{
		vector<Obstacle*> tempObL = lane->getListObstacle();
		out << tempObL.size() << endl;
		for (auto& obs : tempObL)
		{	
			out << obs->getID() << endl;
			out << obs->getCurX() << " " << obs->getCurY() << endl;
		}
		out << lane->getCurY() << " " << lane->getSpeedX() << " " << lane->getRedLight() << endl;
	}
	out << level;
}

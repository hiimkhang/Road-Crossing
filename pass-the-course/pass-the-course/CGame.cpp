#include "CGame.h"
#pragma warning(disable : 4700)
CGame::CGame(int newLevel) :  level(1), isPause(false), isCollised(false)
{
	// initial HUMAN
	human = Human(32, 33);

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
void CGame::drawGame() {
	drawBoard(8);
	human.initial();
	int n = listCLane.size();
	for (int i = 0; i < n; ++i) {
		gotoxy(92, i * 6 + 12);
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
void CGame::drawBoard(int color)
{
	int a = 5;
	int b = 2;
	gotoxy(a, b);
	Textcolor(color);
	// ve duong ngang
	cout << char(220);
	for (int i = 1; i <= 121; i++) {
		if (i == 95) cout << char(220);
		cout << char(220);

	}
	cout << char(220) << endl;
	// ve doc
	for (int i = 1; i <= 36; i++) {
		gotoxy(a, b + i);

		for (int j = 1; j < 123; j++) {
			if (j == 85 || j == 122 || j == 1) cout << char(219);
			cout << " ";

		}
		if ((i) % 6 == 0 && (i) != 0) {
			gotoxy(a + 1, b + i);
			for (int k = 1; k <= 84; k++) {
				if (k % 2 == 0 && k != 0) {
					cout << " ";
				}
				else
					cout << char(205);
			}
		}
	}
	// ve canh day
	gotoxy(a, 38);
	cout << char(223);
	for (int i = 1; i <= 121; i++) {
		if (i == 95) cout << char(223);
		cout << char(223);
	}
	cout << char(223);

}
void CGame::updatePosCLane() {
	if (!isPause) {
		for (auto& clane : listCLane)
		{
			if (clane->getRedLight() == false)
				clane->move();
			else
				clane->print();
		}
	}
}
void CGame::updateRedLight() {
	int n = listCLane.size();
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			listCLane[i]->changeLight();
		}
		gotoxy(92, i * 6 + 12);
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
	//Sleep(200);
	system("cls");
	human.reset();
	human.move();	// return to start position

	int n = listCLane.size();
	for (int i = 0; i < n; ++i) {
		delete listCLane[i];
	}
	listCLane.clear();

}
void CGame::resetLevel() {
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
}
void CGame::setupLevel1() {
	CLane* pC = nullptr;
	pC = new CLane(2, 9);			// clane 2 with 2 cop, y-coordinate is 8
	listCLane.push_back(pC);
	pC = new CLane(1, 15);			// clane 3 with 1 cop, y-coordinate is 16
	pC->updateSpeed(-1);				// speed -1 < 0 -> move to the left
	listCLane.push_back(pC);
	pC = new CLane(1, 21);
	listCLane.push_back(pC);
	pC = new CLane(2, 27);
	pC->updateSpeed(-1);				// speed -1
	listCLane.push_back(pC);
}
void CGame::setupLevel2() {
	CLane* pC = new CLane(3, 9);			// clane 2 with 2 cop, y-coordinate is 8
	listCLane.push_back(pC);
	pC = new CLane(3, 15);			// clane 3 with 1 cop, y-coordinate is 16
	pC->updateSpeed(-1);				// speed -1
	listCLane.push_back(pC);
	pC = new CLane(4, 21);
	listCLane.push_back(pC);
	pC = new CLane(4, 27);
	pC->updateSpeed(-1);				// speed -1
	listCLane.push_back(pC);
}
void CGame::setupLevel3() {
	CLane* pC = new CLane(2, 9);			// clane 2 with 2 cop, y-coordinate is 8
	pC->updateSpeed(2);				// speed -1
	listCLane.push_back(pC);
	pC = new CLane(4, 15);			// clane 3 with 1 cop, y-coordinate is 16
	pC->updateSpeed(-1);				// speed -1
	listCLane.push_back(pC);
	pC = new CLane(2, 21);
	pC->updateSpeed(3);				// speed -1
	listCLane.push_back(pC);
	pC = new CLane(4, 27);			// clane 3 with 1 cop, y-coordinate is 16
	pC->updateSpeed(-1);				// speed -1
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
				human.setIsDead(true);
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
//void CGame::exitGame(HANDLE h) {
//	TerminateThread(h, 0);
//	system("cls");
//	cout << "Thanks for playing the game\n";
//	cout << "Good bye\n";
//}
void CGame::exitThread(thread* t, bool& IS_RUNNING) {
	system("cls");
	IS_RUNNING = false;
	t->join();
	//cout << "\nEXIT game\n";
}
bool CGame::loadGame(string fn)
{
	resetGame();
	clrscr();
	ifstream in(".//Save//" + fn, ios::binary);
	if (!in.is_open()) {
		cout << "We cannot find this file\n";
		return false;
	}
	//human
	
	int* curHuman = new int[2];
	int temp1 = 0, temp2 = 0;
	in.read((char*)&temp1, 4);
	in.read((char*)&temp2, 4);
	//in >> *curHuman >> *(curHuman + 1);
	*curHuman = temp1;
	*(curHuman + 1) = temp2;
	human.setHumanPosition(curHuman);
	int numOfLane = 4;
	in.read((char*)&numOfLane, 4);
	//in >> numOfLane;
	listCLane.clear();
	for (int i = 0; i < numOfLane; i++)
	{
		CLane* lane = new CLane;
		int numOfObs = 2;
		in.read((char*)&numOfObs, 4);
		//in >> numOfObs;
		for (int j = 0; j < numOfObs; j++)
		{
			int id; 
			//in >> id;
			in.read((char*)&id, 4);
			Obstacle* obs = nullptr;
			int tX = 0, tY = 0;
			in.read((char*)&tX, 4);
			in.read((char*)&tY, 4);
			//in >> tX >> tY;
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
		in.read((char*)&y, 4);
		in.read((char*)&x, 4);
		in.read((char*)&rl, 1);
		//in >> y >> x >> rl;
		lane->set(y, x, rl);
		listCLane.push_back(lane);
	}
	int lv;
	//in >> lv;
	in.read((char*)&lv, 4);
	level = lv;
	in.close();
	return true;
}

void CGame::saveGame(string fn)
{
	ofstream out;
	out.open(".//Save//" + fn, ios::binary);
	//from human
	//out << human.getFigDir() << endl; //dir of figure
	int* pos = human.getHumanPosition();
	int t1 = *(pos), t2 = *(pos + 1);
	out.write((char*)&t1, 4);
	out.write((char*)&t2, 4);
	bool b1;
	//out << *(pos) << " " << *(pos + 1) << endl; //position
	t1 = listCLane.size();
	out.write((char*)&t1, 4);
	/*out << listCLane.size() << endl;*/
	for (auto& lane : listCLane)
	{
		vector<Obstacle*> tempObL = lane->getListObstacle();
		t1 = tempObL.size();
		out.write((char*)&t1, 4);
		/*out << tempObL.size() << endl;*/
		for (auto& obs : tempObL)
		{	
			t1 = obs->getID();
			out.write((char*)&t1, 4);
			/*out << obs->getID() << endl;*/
			t1 = obs->getCurX();
			out.write((char*)&t1, 4);
			t1 = obs->getCurY();
			out.write((char*)&t1, 4);
			/*out << obs->getCurX() << " " << obs->getCurY() << endl;*/
		}
		t1 = (lane->getCurY());
		out.write((char*)&t1, 4);
		t1 = lane->getSpeedX();
		out.write((char*)&t1, 4);
		b1 = lane->getRedLight();
		out.write((char*)&b1, 1);
		//out << lane->getCurY() << " " << lane->getSpeedX() << " " << lane->getRedLight() << endl;
	}

	out.write((char*)&level, 4);
	//out << level;
	out.close();
}

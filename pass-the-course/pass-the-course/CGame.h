#ifndef _cgame_h_
#define _cgame_h_

#include <Windows.h>
#include <conio.h>
#include <vector>
#include "console.h"
#include <fstream>
#include "Human.h"
#include "Obstacle.h"
#include "CLane.h"


class CGame
{
	public:
		CGame(int newLevel = 1);
		~CGame(); 
		Human getPeople();
		int getLevel();
		vector<CLane*>& getListCLane();
		void startGame(); 
		void updatePosCLane();
		void drawGame();
		void levelTransfer();
		void drawBoard(int color);
		void drawTrafficLight(int color);
		void updatePosPeople(char); 
		void updateRedLight();
		bool isCollided();
		bool isFinish();
		void levelUp();
		void resetGame(); 
		void resetLevel();
		void setupLevel1();
		void setupLevel2();
		void setupLevel3();
		void setupLevel4();
		void pauseGame(HANDLE); 
		void resumeGame(HANDLE); 
		void exitGame(HANDLE); 
		void exitThread(thread* t, bool& IS_RUNNING);
		bool loadGame(string fn); 
		
		void saveGame(string fn); 

	private:	
		Human human;
		vector<CLane*> listCLane;
		vector<string> saveFile;
		bool isPause;
		bool isCollised;
		int level;
};

#endif // !_cgame_h_

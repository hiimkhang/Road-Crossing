#ifndef _cgame_h_
#define _cgame_h_

#include <Windows.h>
#include <conio.h>
#include <vector>
#include <chrono>	// for time related work
#include <ctime>	// for time related work
#include "console.h"

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
		void updatePosPeople(char); 
		void updateRedLight();
		bool isCollided();
		bool isFinish();
		void levelUp();
		void resetGame(); 
		void setupLevel1();
		void setupLevel2();
		void setupLevel3();
		void pauseGame(HANDLE); 
		void resumeGame(HANDLE); 
		void exitGame(HANDLE); 
		/* 
		void loadGame(istream); 
		void saveGame(istream); 
		*/
	private:	
		Human human;
		vector<CLane*> listCLane;
		bool isPause;
		bool isCollised;
		int level;
		clock_t clockStart;

};

#endif // !_cgame_h_

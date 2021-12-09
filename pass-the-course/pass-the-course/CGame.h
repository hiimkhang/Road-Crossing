#ifndef _cgame_h_
#define _cgame_h_

#include <vector>
#include "console.h"
#include "Human.h"
#include "Obstacle.h"
#include "CLane.h"

class CGame
{
	public:
		CGame();
		~CGame(); 
		Human getPeople();
		vector<CLane*>& getListCLane();
		void startGame(); 
		void updatePosCLane();
		void drawGame();
		void updatePosPeople(char); 
		bool isCollided();
		bool isFinish();
		void resetPeople();
		void levelUp();
		/* 
		void resetGame(); 
		void exitGame(HANDLE); 
		void loadGame(istream); 
		void saveGame(istream); 
		void pauseGame(HANDLE); 
		void resumeGame(HANDLE); 
		*/
	private:	
		Human human;
		vector<CLane*> listCLane;
		bool isPause;
		bool isCollised;

};

#endif // !_cgame_h_

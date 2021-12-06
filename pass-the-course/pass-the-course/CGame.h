#ifndef _cgame_h_
#define _cgame_h_

#include <vector>
#include "console.h"
#include "Human.h"
#include "Obstacle.h"

class CGame
{
	public:
		CGame();
		~CGame(); 
		Human getPeople();
		vector<Obstacle*>& getListObstacle();
		void startGame(); 
		void updatePosObstacle();
		void drawGame();
		/* 
		void resetGame(); 
		void exitGame(HANDLE); 
		void loadGame(istream); 
		void saveGame(istream); 
		void pauseGame(HANDLE); 
		void resumeGame(HANDLE); 
		void updatePosPeople(char); 
		void updatePosVehicle(); 
		void updatePosAnimal();*/
	private:	
		Human human;
		vector<Obstacle*> listObstacle;
		bool isPause;
		bool isCollised;

};

#endif // !_cgame_h_

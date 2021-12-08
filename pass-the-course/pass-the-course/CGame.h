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
		vector<CLane*> listCLane;
		bool isPause;
		bool isCollised;

};

#endif // !_cgame_h_

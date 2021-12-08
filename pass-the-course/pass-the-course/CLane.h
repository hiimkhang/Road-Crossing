#ifndef _cLane_h_
#define _cLane_h_
#include "Obstacle.h"
#include <vector>
#include <thread>
class CLane
{
private:
	std::vector<Obstacle*> list;
	std::thread th;
public:
	void run();
};

#endif // !_cLane_h_

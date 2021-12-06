#ifndef _Figure_h_
#define _Figure_h_
#include <fstream>
#include <vector>
#include <string>
#include "console.h"
class Figure
{
private:
	std::vector<std::vector<int>> symbol, color;
	int sizeX, sizeY;
public:
	Figure();
	Figure(std::string dir);
	void print(int x, int y);
	void deleteFootprint(int x, int y);
};
#endif // _Figure_h_

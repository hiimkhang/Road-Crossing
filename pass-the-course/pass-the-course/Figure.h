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
	string dir;
public:
	Figure();
	Figure(std::string dir);
	void print(int x, int y);
	void deleteFootprint(int x, int y);
	string getDir();
	void setDir(string d);
};
#endif // _Figure_h_

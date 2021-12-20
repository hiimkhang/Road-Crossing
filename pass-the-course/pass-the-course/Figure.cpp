
#include "Figure.h"

Figure::Figure()
{

}

Figure::Figure(std::string dir)
{
	std::ifstream fig(dir);
	this->dir = dir;
	fig >> sizeX;
	fig >> sizeY;
	for (int i = 0; i < sizeY; i++)
	{
		std::vector<int> tv;
		for (int j = 0; j < sizeX; j++)
		{
			int ti;
			fig >> ti;
			tv.push_back(ti);
		}
		symbol.push_back(tv);
	}
	for (int i = 0; i < sizeY; i++)
	{
		std::vector<int> tv;
		for (int j = 0; j < sizeX; j++)
		{
			int ti;
			fig >> ti;
			tv.push_back(ti);
		}
		color.push_back(tv);
	}
}

void Figure::print(int x, int y)
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (symbol[i][j])
			{
				Textcolor(color[i][j]);
				gotoxy(x + j, y + i);
				std::cout << char(symbol[i][j]);
			}
		}
	}
}

void Figure::deleteFootprint(int x, int y)
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			gotoxy(x + j, y + i);
			std::cout << " ";
		}
	}
}

string Figure::getDir()
{
	return dir;
}

void Figure::setDir(string d)
{
	dir = d;
	std::ifstream fig(dir);
	this->dir = dir;
	fig >> sizeX;
	fig >> sizeY;
	for (int i = 0; i < sizeY; i++)
	{
		std::vector<int> tv;
		for (int j = 0; j < sizeX; j++)
		{
			int ti;
			fig >> ti;
			tv.push_back(ti);
		}
		symbol.push_back(tv);
	}
	for (int i = 0; i < sizeY; i++)
	{
		std::vector<int> tv;
		for (int j = 0; j < sizeX; j++)
		{
			int ti;
			fig >> ti;
			tv.push_back(ti);
		}
		color.push_back(tv);
	}
}

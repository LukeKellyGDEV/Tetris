#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
	Grid();
	void Initialize();
	void Draw();
	void Print();
	int GridArray[20][10];
private:
	std::vector<Color> GetCellColours();
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> Colours;
};


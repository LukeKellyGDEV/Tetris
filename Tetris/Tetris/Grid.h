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
	bool IsCellOustide(int Row, int Column);
	int GridArray[20][10];
private:
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> Colours;
};


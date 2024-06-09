#pragma once

class Grid
{
public:
	Grid();
	void Initialize();
	void Print();
	int GridArray[20][10];
private:
	int NumRows;
	int NumCols;
	int CellSize;
};


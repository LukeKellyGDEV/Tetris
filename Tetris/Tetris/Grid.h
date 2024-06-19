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
	bool IsCellEmpty(int Row, int Column);
	int ClearFullRows();
	int GridArray[20][10];
private:
	bool IsRowFull(int Row);
	void ClearRow(int Row);
	void MoveRowDown(int Row, int NumRows);
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> Colours;
};


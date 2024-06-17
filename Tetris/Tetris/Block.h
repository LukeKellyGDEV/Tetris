#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colours.h"

class Block
{
public:
	Block();
	void Draw();
	void Move(int Rows, int Columns);
	std::vector<Position> GetCellPositions();
	int ID;
	std::map<int, std::vector<Position>> Cells;
private:
	int CellSize;
	int RotationState;
	std::vector<Color> Colours;
	int RowOffset;
	int ColumnOffset;
};


#include "Block.h"

Block::Block()
{
	CellSize = 30;
	RotationState = 0;
	Colours = GetCellColours();
	RowOffset = 0;
	ColumnOffset = 0;
}

void Block::Draw()
{
	std::vector<Position> Tiles = GetCellPositions();
	for (Position Item : Tiles)
	{
		DrawRectangle(Item.Column * CellSize + 1, Item.Row * CellSize + 1, CellSize - 1, CellSize - 1, Colours[ID]);
	}
}

void Block::Move(int Rows, int Columns)
{
	RowOffset += Rows;
	ColumnOffset += Columns;
}

std::vector<Position> Block::GetCellPositions()
{
	std::vector<Position> Tiles = Cells[RotationState];
	std::vector<Position> MovedTiles;
	for(Position Item: Tiles)
	{
		Position NewPos = Position(Item.Row + RowOffset, Item.Column + ColumnOffset);
		MovedTiles.push_back(NewPos);
	}
	return MovedTiles;
}
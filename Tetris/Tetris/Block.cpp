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
		DrawRectangle(Item.Column * CellSize + 11, Item.Row * CellSize + 11, CellSize - 1, CellSize - 1, Colours[ID]);
	}
}

void Block::Move(int Rows, int Columns)
{
	RowOffset += Rows;
	ColumnOffset += Columns;
}

void Block::Rotate()
{
	RotationState++;
	if (RotationState == (int)Cells.size())
	{
		RotationState = 0;
	}
}

void Block::UndoRotation()
{
	RotationState--;
	if (RotationState == -1)
	{
		RotationState = Cells.size() - 1;
	}
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
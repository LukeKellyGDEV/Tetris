#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	Initialize();
	Colours = GetCellColours();
}

void Grid::Initialize()
{
	for (int Row = 0; Row < NumRows; Row++)
	{
		for (int Column = 0; Column < NumCols; Column++)
		{
			GridArray[Row][Column] = 0;
		}
	}
}

void Grid::Draw()
{
	for (int Row = 0; Row < NumRows; Row++)
	{
		for (int Column = 0; Column < NumCols; Column++)
		{
			int CellValue = GridArray[Row][Column];
			DrawRectangle(Column * CellSize, Row * CellSize, CellSize, CellSize, Colours[CellSize]);
		}
	}
}

void Grid::Print()
{
	for (int Row = 0; Row < NumRows; Row++)
	{
		for (int Column = 0; Column < NumCols; Column++)
		{
			std::cout << GridArray[Row][Column] << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<Color> Grid::GetCellColours()
{
	Color DarkGrey = {26, 31, 40, 255};
	Color Green = {47, 230, 23, 255};
	Color Red = {232, 18, 18, 255};
	Color Orange = {226, 116, 17, 255};
	Color Yellow = {237, 234, 4, 255};
	Color Purple = {166, 0, 247, 255};
	Color Cyan = {21, 204, 209, 255};
	Color Blue = {13, 64, 216, 255};

	return {DarkGrey, Green, Red, Orange, Yellow, Purple, Cyan, Blue};
}			
#include "Grid.h"
#include <iostream>
#include "Colours.h"

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
			DrawRectangle(Column * CellSize + 1, Row * CellSize + 1, CellSize -1, CellSize -1, Colours[CellValue]);
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
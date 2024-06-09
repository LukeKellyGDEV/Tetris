#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	Initialize();
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

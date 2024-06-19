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

bool Grid::IsCellOustide(int Row, int Column)
{
	if (Row >= 0 && Row < NumRows && Column >= 0 && Column < NumCols)
	{
		return false;
	}

	return true;

}

bool Grid::IsCellEmpty(int Row, int Column)
{
	if (GridArray[Row][Column] == 0)
	{
		return true;
	}
	return false;
}

int Grid::ClearFullRows()
{
	int Completed = 0;
	for (int Row = NumRows-1; Row >= 0; Row--)
	{
		if (IsRowFull(Row))
		{
			ClearRow(Row);
			Completed++;
		}
		else if (Completed > 0)
		{
			MoveRowDown(Row, Completed);
		}
	}
	return Completed;
}

bool Grid::IsRowFull(int Row)
{
	for (int Column = 0; Column < NumCols; Column++)
	{
		if (GridArray[Row][Column] == 0)
		{
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int Row)
{
	for (int Column = 0; Column < NumCols; Column++)
	{
		GridArray[Row][Column] = 0;
	}
}

void Grid::MoveRowDown(int Row, int NumRows)
{
	for (int Column = 0; Column < NumCols; Column++)
	{
		GridArray[Row + NumRows][Column] = GridArray[Row][Column];
		GridArray[Row][Column] = 0;
	}
}

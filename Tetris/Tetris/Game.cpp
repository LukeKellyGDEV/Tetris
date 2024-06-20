#include "Game.h"
#include <random>
#include <iostream>

Game::Game()
{
	grid = Grid();
	Blocks = GetAllBlocks();
	CurrentBlock = GetRandomBlock();
	NextBlock = GetRandomBlock();
	GameOver = false;
}

Block Game::GetRandomBlock()
{
	if (Blocks.empty())
	{
		Blocks = GetAllBlocks();
	}

	int RandomIndex = rand() % Blocks.size();
	Block Block = Blocks[RandomIndex];
	Blocks.erase(Blocks.begin() + RandomIndex);
	return Block;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw()
{
	grid.Draw();
	CurrentBlock.Draw();
}

void Game::HandleInput()
{
	int KeyPressed = GetKeyPressed();
	switch(KeyPressed)
	{
		case KEY_LEFT:
			MoveBlockLeft();
			break;
		case KEY_RIGHT:
			MoveBlockRight();
			break;
		case KEY_DOWN:
			MoveBlockDown();
			break;
		case KEY_UP:
			RotateBlock();
			break;
		case KEY_ENTER:
			Gameover();
			break;
		case KEY_SPACE:
			Gameover();
			break;
	}
}

void Game::MoveBlockLeft()
{
	if (!GameOver)
	{
		CurrentBlock.Move(0, -1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			CurrentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!GameOver)
	{
		CurrentBlock.Move(0, 1);
		if (IsBlockOutside() || BlockFits() == false)
		{
			CurrentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!GameOver)
	{
		CurrentBlock.Move(1, 0);
		if (IsBlockOutside() || BlockFits() == false)
		{
			CurrentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsBlockOutside()
{
	std::vector<Position> Tiles = CurrentBlock.GetCellPositions();
	for (Position Item: Tiles)
	{
		if (grid.IsCellOustide(Item.Row, Item.Column))
		{
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()
{
	if (!GameOver)
	{
		CurrentBlock.Rotate();
		if (IsBlockOutside() || BlockFits() == false)
		{
			CurrentBlock.UndoRotation();
		}
	}
}

void Game::LockBlock()
{
	std::vector<Position> Tiles = CurrentBlock.GetCellPositions();
	for (Position Item : Tiles)
	{
		grid.GridArray[Item.Row][Item.Column] = CurrentBlock.ID;
	}
	CurrentBlock = NextBlock;
	if (BlockFits() == false)
	{
		GameOver = true;
	}
	NextBlock = GetRandomBlock();
	grid.ClearFullRows();
}

bool Game::BlockFits()
{
	std::vector<Position> Tiles = CurrentBlock.GetCellPositions();
	for (Position Item : Tiles)
	{
		if (grid.IsCellEmpty(Item.Row, Item.Column) == false)
		{
			return false;
		}
	}
	return true;
}

void Game::Reset()
{
	grid.Initialize();
	Blocks = GetAllBlocks();
	CurrentBlock = GetRandomBlock();
	NextBlock = GetRandomBlock();
}

void Game::Gameover()
{
	if (GameOver)
	{
		GameOver = false;
		Reset();
	}
}

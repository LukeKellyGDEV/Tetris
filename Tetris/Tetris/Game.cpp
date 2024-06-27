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
	Pause = false;
	Score = 0;
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
	CurrentBlock.Draw(11, 11);
	switch (NextBlock.ID)
	{
	case 3:
		NextBlock.Draw(255, 290);
		break;
	case 4:
		NextBlock.Draw(255, 275);
		break;
	default:
		NextBlock.Draw(270, 270);
		break;
	}
}

void Game::HandleInput()
{
	int KeyPressed = GetKeyPressed();
	switch (KeyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		if (!GameOver && !Pause) UpdateScore(0, 1);
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
	case KEY_P:
		if(Pause == false)
		{
			Pause = true;
			return;
		}
		else
		{
			Pause = false;
			return;
		}
		break;
	}
}

void Game::MoveBlockLeft()
{
	if (!GameOver && !Pause)
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
	if (!GameOver && !Pause)
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
	if (!GameOver && !Pause)
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
	if (!GameOver && !Pause)
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
	int RowsCleared = grid.ClearFullRows();
	UpdateScore(RowsCleared, 0);
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
	Score = 0;
	GameSpeed = 0.3;
}

void Game::Gameover()
{
	if (GameOver)
	{
		GameOver = false;
		Reset();
	}
}

void Game::UpdateScore(int LinesCleared, int MoveDownPoints)
{
	switch (LinesCleared)
	{
	case 1:
		Score += 50;
		break;
	case 2:
		Score += 125;
		break;
	case 3:
		Score += 300;
		break;
	default:
		break;
	}
	if (LinesCleared > 3)
	{
		Score += 500;
	}
	Score += MoveDownPoints;
}

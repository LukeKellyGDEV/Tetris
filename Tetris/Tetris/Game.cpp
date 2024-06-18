#include "Game.h"
#include <random>

Game::Game()
{
	grid = Grid();
	Blocks = GetAllBlocks();
	CurrentBlock = GetRandomBlock();
	NextBlock = GetRandomBlock();
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

	}
}

void Game::MoveBlockLeft()
{
	CurrentBlock.Move(0, -1);
	if (IsBlockOutside())
	{
		CurrentBlock.Move(0, 1);
	}
}

void Game::MoveBlockRight()
{
	CurrentBlock.Move(0, 1);
	if (IsBlockOutside())
	{
		CurrentBlock.Move(0, -1);
	}
}

void Game::MoveBlockDown()
{
	CurrentBlock.Move(1, 0);
	if (IsBlockOutside())
	{
		CurrentBlock.Move(-1, 0);
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

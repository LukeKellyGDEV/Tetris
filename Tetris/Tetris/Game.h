#pragma once
#include "Grid.h"
#include "Blocks.cpp"

class Game
{
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
	Grid grid;
	bool Pause;
	bool GameOver;
	int Score;
	double GameSpeed = 0.3;
private:
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void Gameover();
	void UpdateScore(int LinesCleared, int MoveDownPoints);
	std::vector<Block> Blocks;
	Block CurrentBlock;
	Block NextBlock;
};


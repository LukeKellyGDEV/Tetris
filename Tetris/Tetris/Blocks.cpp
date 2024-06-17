#include "Block.h"
#include "Position.h"

class LBlock : public Block
{
public:
	LBlock() 
	{ 
		ID = 1;
		Cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
		Cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
		Cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
		Cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class JBlock : public Block
{
public:
	JBlock()
	{
		ID = 2;
		Cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
		Cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
		Cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
		Cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
		Move(0, 3);
	}
};

class IBlock : public Block
{
public:
	IBlock()
	{
		ID = 3;
		Cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
		Cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
		Cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
		Cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
		Move(0, 3);
	}
};

class OBlock : public Block
{
public:
	OBlock()
	{
		ID = 4;
		Cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Cells[1] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Cells[2] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Cells[3] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		Move(0, 3);
	}
};

class SBlock : public Block
{
public:
	SBlock()
	{
		ID = 5;
		Cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
		Cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
		Cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
		Cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class TBlock : public Block
{
public:
	TBlock()
	{
		ID = 6;
		Cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
		Cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
		Cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
		Cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
		Move(0, 3);
	}
};

class ZBlock : public Block
{
public:
	ZBlock()
	{
		ID = 7;
		Cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
		Cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
		Cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
		Cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
		Move(0, 3);
	}
};
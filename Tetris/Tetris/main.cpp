#include <raylib.h>
#include "Grid.h"
#include "Blocks.cpp"

int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 630, "Tetris");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	TBlock block = TBlock();

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(DarkBlue);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}


	CloseWindow();
}

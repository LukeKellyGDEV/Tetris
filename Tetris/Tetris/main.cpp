#include <raylib.h>
#include "Grid.h"

int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(DarkBlue);

		EndDrawing();
	}


	CloseWindow();
}

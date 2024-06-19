#include <raylib.h>
#include "Game.h"

double LastUpdateTime = 0;

bool EventTriggered(double Interval)
{
	double CurrentTime = GetTime();
	if (CurrentTime - LastUpdateTime >= Interval)
	{
		LastUpdateTime = CurrentTime;
		return true;
	}
	return false;
}

int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "Tetris");
	SetTargetFPS(60);

	Game game = Game();
	
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (EventTriggered(0.3))
		{
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(DarkBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}

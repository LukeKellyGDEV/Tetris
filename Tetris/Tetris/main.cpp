#include <raylib.h>
#include "Game.h"
#include "Colours.h"

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
	InitWindow(500, 620, "Tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/Simple.ttf", 64, 0, 0);

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
		DrawTextEx(font, "Score", { 350, 15 }, 38, 2, WHITE);
		DrawTextEx(font, "Next", { 360, 175 }, 38, 2, WHITE);
		DrawTextEx(font, "Game Over", { 325, 450 }, 32, 2, WHITE);
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, LightBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}

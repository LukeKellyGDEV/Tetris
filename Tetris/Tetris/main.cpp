#include <raylib.h>
#include "Game.h"
#include "Colours.h"
#include <iostream>

double LastUpdateTime = 0;
double GameSpeed = 0.3;

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
	double GameSpeed = 0.3;
	InitWindow(500, 620, "Tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/Retroica.ttf", 64, 0, 0);

	Game game = Game();
	
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (game.Score >= 100)
		{
			GameSpeed = 0.1;
		}
		if (EventTriggered(GameSpeed))
		{
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(DarkBlue);
		DrawTextEx(font, "Score", { 345, 15 },38 ,2 , WHITE);
		DrawTextEx(font, "Next", { 355, 175 },38 ,2 , WHITE);
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, LightBlue);

		char ScoreText[10];
		sprintf_s(ScoreText, "%d", game.Score);
		Vector2 TextSize = MeasureTextEx(font, ScoreText, 38, 2);

		DrawTextEx(font, ScoreText, { 320 + (170 - TextSize.x)/2, 70 }, 38, 2, WHITE);

		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, LightBlue);
		game.Draw();
		if (game.GameOver)
		{
			DrawTextEx(font, "Game Over", { 325, 450 }, 24, 2, WHITE);
			DrawTextEx(font, "Press Space", { 320, 485}, 24, 2, WHITE);
			DrawTextEx(font, "or Enter Key", { 315, 520}, 24, 2, WHITE);
			DrawTextEx(font, "to Restart", { 330, 555 }, 24, 2, WHITE);
		}
		EndDrawing();
	}
	UnloadFont(font);

	CloseWindow();
}

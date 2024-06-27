#include <raylib.h>
#include "Game.h"
#include "Colours.h"
#include <iostream>

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
	double GameSpeed = 0.3;
	InitWindow(700, 620, "Tetris");
	SetTargetFPS(60);
	std::cout << LastUpdateTime << std::endl;

	Font font = LoadFontEx("Font/Retroica.ttf", 64, 0, 0);

	Game game = Game();
	
	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (game.Pause == false && game.GameOver == false)
		{
			if (EventTriggered(game.GameSpeed))
			{
				game.MoveBlockDown();
			}
		}
		if (game.grid.RowsCompleted >= 10)
		{
			game.grid.RowsCompleted = 0;
			game.GameSpeed -= 0.01;
		}
		BeginDrawing();
		ClearBackground(DarkBlue);
		DrawTextEx(font, "Score", { 365, 25 },24 ,2 , WHITE);
		DrawTextEx(font, "Next", { 370, 185 },24 ,2 , WHITE);
		DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, LightBlue);

		char ScoreText[10];
		sprintf_s(ScoreText, "%d", game.Score);
		Vector2 TextSize = MeasureTextEx(font, ScoreText, 38, 2);

		DrawTextEx(font, ScoreText, { 320 + (170 - TextSize.x)/2, 70 }, 38, 2, WHITE);

		DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, LightBlue);
		game.Draw();
		
		//LeaderBoard
		DrawTextEx(font, "Leaderboard:", { 505, 25 },24 ,2 , WHITE);
		DrawRectangleRounded({ 505, 55, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 110, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 165, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 220, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 275, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 330, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 385, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 440, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 495, 180, 40 }, 0.3, 6, LightBlue);
		DrawRectangleRounded({ 505, 550, 180, 40 }, 0.3, 6, LightBlue);

		if (game.GameOver)
		{
			DrawTextEx(font, "Game Over", { 325, 450 }, 24, 2, RED);
			DrawTextEx(font, "Press Space", { 320, 485}, 24, 2, WHITE);
			DrawTextEx(font, "or Enter Key", { 315, 520}, 24, 2, WHITE);
			DrawTextEx(font, "to Restart", { 330, 555 }, 24, 2, WHITE);
		}
		else
		{
			if (game.Pause)
			{
				DrawTextEx(font, "Paused", { 350, 450 }, 24, 2, RED);
			}
			DrawTextEx(font, "Press P", { 350, 485 }, 24, 2, WHITE);
			DrawTextEx(font, "To Pause", { 340, 520 }, 24, 2, WHITE);
		}
		EndDrawing();
	}
	UnloadFont(font);

	CloseWindow();
}

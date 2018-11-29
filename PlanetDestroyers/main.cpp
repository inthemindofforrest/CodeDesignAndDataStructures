#include "MainMenu.h"
#include "GameStates.h"
#include "LevelManager.h"
#include "GameplayManager.h"
#include <time.h>

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Planet Destroyers");
	SetTargetFPS(60);

	srand(time(NULL));

	MainMenuScreen::GetInstance();
	GameState::GetInstance();
	GameplayManager::GetInstance().InitPlanets(100);
	std::string Score;

	while (!WindowShouldClose())  
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (GameState::GetInstance().getState())
		{
		case 0://MainMenu
			MainMenuScreen::GetInstance().Update();
			break;
		case 1://LevelSelection
			ClearBackground(BLACK);
			LevelManager::GetInstance().Update();
			break;
		case 2://Options
			ClearBackground(BLACK);
			MainMenuScreen::GetInstance().Update();
			break;
		case 3://GameOver
			ClearBackground(BLACK);
			Score.clear();
			Score.append("Score: " + std::to_string(GameplayManager::GetInstance().Score));
			DrawText(Score.c_str(), (GetScreenWidth() / 2) - (MeasureText(Score.c_str(), 25) / 2), GetScreenHeight() / 2, 25, WHITE);
			DrawText("Press Space", (GetScreenWidth() / 2) - (MeasureText("Press Space", 25) / 2), (GetScreenHeight() / 10 ) * 7, 25, WHITE);

			if (IsKeyPressed(KEY_SPACE))
			{
				CloseWindow();
				return 0;
			}
			break;
		case 4://Level 1
			ClearBackground(BLACK);
			GameplayManager::GetInstance().Update(0);
			break;
		case 5://Level 2
			ClearBackground(BLACK);
			GameplayManager::GetInstance().Update(1);
			break;
		default:
			break;
		} 


		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
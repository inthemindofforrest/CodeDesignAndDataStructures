#include "MainMenu.h"
#include "GameStates.h"
#include "LevelManager.h"
#include "GameplayManager.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Planet Destroyers");
	SetTargetFPS(60);

	MainMenuScreen::GetInstance();
	GameState::GetInstance();
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
			ClearBackground(DARKGREEN);
			LevelManager::GetInstance().Update();
			break;
		case 2://Options
			ClearBackground(DARKPURPLE);
			MainMenuScreen::GetInstance().Update();
			break;
		case 3://GameOver
			CloseWindow();
			return 0;
			break;
		case 4://Level 1
			ClearBackground(GRAY);
			GameplayManager::GetInstance().InitPlanets(1);
			GameplayManager::GetInstance().Update();
			break;
		case 5://Level 2
			ClearBackground(DARKBLUE);
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
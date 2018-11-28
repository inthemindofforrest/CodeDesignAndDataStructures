#include "GameplayManager.h"

GameplayManager::GameplayManager() {}
GameplayManager::~GameplayManager() {}
GameplayManager::GameplayManager(GameplayManager const&) {}
void GameplayManager::operator=(GameplayManager const&) {}

GameplayManager& GameplayManager::GetInstance()
{
	static GameplayManager Instance;
	return Instance;
}

void GameplayManager::Update()
{
	for (int i = 0; i < 100; i++)
	{
		if (PlanetIsActive[i] == 1)
		{
			ArrOfPlanets[i].Update(ArrOfBullets, PlanetIsActive);

			if (PlanetIsActive[i] == 1 && ArrOfPlanets[i].Rect.y > GetScreenHeight())
			{
				GameState::GetInstance().setState(3);
			}

		}
	}


}

void GameplayManager::InitPlanets(int Level)
{


}
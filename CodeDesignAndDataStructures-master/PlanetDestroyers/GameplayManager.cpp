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

void GameplayManager::SpawnBlackHole()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		LeftBlackHole.Rect = { (float)GetMouseX(), (float)GetMouseY(), LeftBlackHole.Rect.width, LeftBlackHole.Rect.height };
		LeftBlackHole.IsActive = true;
	}
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		RightBlackHole.Rect = { (float)GetMouseX(), (float)GetMouseY(), RightBlackHole.Rect.width, RightBlackHole.Rect.height };
		RightBlackHole.IsActive = true;
	}
}

void GameplayManager::Update()
{
	SpawnBlackHole();
	LeftBlackHole.Draw();
	RightBlackHole.Draw();
	ControlledPlanet.Draw();
	DestinationPlanet.Draw();

	if (LeftBlackHole.IsActive && RightBlackHole.IsActive)
	{
		//Move Controlled planet towards the LEFT blackhole
		Vector2 Direction = RatioOfDistance((LeftBlackHole.Rect.x - ControlledPlanet.Rect.x), (LeftBlackHole.Rect.y - ControlledPlanet.Rect.y));
		//ControlledPlanet.MovePlanet(Direction);
	}
}

Vector2 GameplayManager::RatioOfDistance(float x, float y)
{
	float Hyp = sqrt(x*x + y * y);
	float newX = x / Hyp;
	float newY = y / Hyp;

	return{ newX, newY };
}

void GameplayManager::InitPlanets(int Level)
{
	
	switch (Level)
	{
	case 1:
		LevelOne Temp;
		ControlledPlanet.Rect.x = Temp.PlanetOneRect.x;
		ControlledPlanet.Rect.y = Temp.PlanetOneRect.y;

		DestinationPlanet.Rect.x = Temp.PlanetTwoRect.x;
		DestinationPlanet.Rect.x = Temp.PlanetTwoRect.y;
		break;
	}
}
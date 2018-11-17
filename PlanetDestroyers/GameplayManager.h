#pragma once
#include "raylib.h"
#include "Blackhole.h"
#include "Planet.h"
#include "Levels.h"
#include <vector>

class GameplayManager
{
	GameplayManager();
	~GameplayManager();
	GameplayManager(GameplayManager const&);
	void operator=(GameplayManager const&);

	BlackHole LeftBlackHole;
	BlackHole RightBlackHole;

	Planet ControlledPlanet;
	Planet DestinationPlanet;

	Vector2 RatioOfDistance(float x, float y);

public:
	void SpawnBlackHole();
	void Update();
	void InitPlanets(int Level);

	static GameplayManager& GetInstance();

};
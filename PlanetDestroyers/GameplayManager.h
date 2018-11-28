#pragma once
#include "raylib.h"
#include "Blackhole.h"
#include "Planet.h"
#include "Levels.h"
#include "Bullet.h"

#include"GameStates.h"
#include <vector>

class GameplayManager
{
	GameplayManager();
	~GameplayManager();
	GameplayManager(GameplayManager const&);
	void operator=(GameplayManager const&);

	std::vector<Planet> ArrOfPlanets;
	std::vector<int> PlanetIsActive;

	std::vector<Bullet> ArrOfBullets;
	std::vector<int> BulletIsActive;

public:
	void Update();
	void InitPlanets(int Level);

	static GameplayManager& GetInstance();

};
#pragma once
#include "raylib.h"
#include "Blackhole.h"
#include "Planet.h"
#include "Levels.h"
#include "Bullet.h"
#include "ThePlayer.h"

#include"GameStates.h"
#include <vector>
#include <string>

class GameplayManager
{
	GameplayManager();
	~GameplayManager();
	GameplayManager(GameplayManager const&);
	void operator=(GameplayManager const&);

	std::vector<Planet> ArrOfPlanets;

	std::vector<Bullet> ArrOfBullets;

	
	
	Player MainPlayer;

public:
	int Score = 0;
	void Update(int Difficulty);
	void InitPlanets(int TotalPool);

	static GameplayManager& GetInstance();

};
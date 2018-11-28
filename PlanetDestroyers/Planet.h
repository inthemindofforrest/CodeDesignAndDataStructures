#pragma once
#include"raylib.h"
#include <vector>
#include "Bullet.h"

struct Planet
{
	Rectangle Rect;
	Texture2D Texture;

	Vector2 Velocity;

	void Draw();
	void MovePlanet(Vector2 Direction);
	void Update(std::vector<Bullet> ArrOfBullets, std::vector<int> PlanetIsActive);

	Planet();
	Planet(Rectangle rect, Texture2D texture);
};
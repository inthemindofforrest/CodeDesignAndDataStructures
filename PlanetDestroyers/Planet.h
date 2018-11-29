#pragma once
#include"raylib.h"
#include <vector>
#include "Bullet.h"

struct Planet
{
	Rectangle Rect;
	Texture2D Texture;

	bool isActive;

	void Draw();
	void MovePlanet(Vector2 Direction);
	void Update();

	Planet();
	Planet(Rectangle rect, Texture2D texture);
};
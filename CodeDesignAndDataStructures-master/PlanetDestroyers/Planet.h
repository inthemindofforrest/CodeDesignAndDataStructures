#pragma once
#include"raylib.h"

struct Planet
{
	Rectangle Rect;
	Texture2D Texture;

	Vector2 Velocity;

	void Draw();
	void MovePlanet(Vector2 Direction);

	Planet();
	Planet(Rectangle rect, Texture2D texture);
};
#pragma once
#include"raylib.h"
#include <vector>

struct Bullet
{
	Rectangle Rect;
	Texture2D Texture;

	Vector2 Velocity;

	void Draw();
	void MoveBullet(Vector2 Direction);

	Bullet();
	Bullet(Rectangle rect, Texture2D texture);
};
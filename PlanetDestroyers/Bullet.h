#pragma once
#include"raylib.h"
#include <vector>

struct Bullet
{
	Rectangle Rect;
	Texture2D Texture;

	bool isActive;

	void Draw();
	void MoveBullet(Vector2 Direction);
	void Update();

	Bullet();
	Bullet(Rectangle rect, Texture2D texture);
};
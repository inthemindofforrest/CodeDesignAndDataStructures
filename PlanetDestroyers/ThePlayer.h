#pragma once
#include"raylib.h"
#include <vector>
#include "Bullet.h"

struct Player
{
	Rectangle Rect;
	Texture2D Texture;

	Vector2 Velocity;

	void Draw();
	void MovePlayer(Vector2 Direction);
	void Update(std::vector<Bullet> BulletsAreActive);

	Player();
	Player(Rectangle rect, Texture2D texture);
};
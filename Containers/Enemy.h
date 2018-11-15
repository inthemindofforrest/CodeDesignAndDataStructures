#pragma once
#include "raylib.h"


class ENEMY
{
	Texture2D Texture;
	Rectangle Rect;
public:
	ENEMY();
	ENEMY(Texture2D texture, Rectangle rect);

	bool IsClicked();
	Vector2 GetPosition();
	void Update();
};
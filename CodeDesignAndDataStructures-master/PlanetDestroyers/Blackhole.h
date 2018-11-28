#pragma once
#include "raylib.h"

struct BlackHole
{
public:
	Rectangle Rect;
	Texture2D Texture;

	bool IsActive;

	void Draw();
	BlackHole();
	BlackHole(Rectangle rect, Texture2D texture);
};
#pragma once
#include "raylib.h"
#include <string>
#include <iostream>
#include <vector>

struct Button
{
	std::string Name;
	Rectangle Rect;
	Texture2D Texture;
	void Draw(int Size);
	Button(std::string name, Rectangle rect, Texture2D texture);
};
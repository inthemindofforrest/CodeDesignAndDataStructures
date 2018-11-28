#include "Planet.h"

Planet::Planet() 
{
	Velocity = { 0,0 };
}
Planet::Planet(Rectangle rect, Texture2D texture)
{
	Velocity = { 0,0 };
	Rect = rect;
	Texture = texture;
}

void Planet::Draw()
{
	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, 1, WHITE);
}
void Planet::MovePlanet(Vector2 Direction)
{
	Rect.x += Direction.x;
	Rect.y += Direction.y;
}

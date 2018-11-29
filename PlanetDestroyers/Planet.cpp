#include "Planet.h"


Planet::Planet()
{
	isActive = false;
}
Planet::Planet(Rectangle rect, Texture2D texture)
{
	Rect = rect;
	Texture = texture;
	isActive = false;
}

void Planet::Draw()
{
	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, .5f, WHITE);
}
void Planet::MovePlanet(Vector2 Direction)
{
	Rect.y += Direction.y;
}

void Planet::Update()
{
	if (isActive)
	{
		Draw();
		MovePlanet({ 0,1 });
	}
}

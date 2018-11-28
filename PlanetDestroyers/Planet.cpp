#include "Planet.h"


Planet::Planet()
{
	Velocity = { 0,0 };
}
Planet::Planet(Rectangle rect, Texture2D texture)
{
	Velocity = { 0,1 };
	Rect = rect;
	Texture = texture;
}

void Planet::Draw()
{
	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, 1, WHITE);
}
void Planet::MovePlanet(Vector2 Direction)
{
	Rect.y += Direction.y;
}

void Planet::Update(std::vector<Bullet> ArrOfBullets, std::vector<int> PlanetIsActive)
{
	Draw();
	for (int i = 0; i < 100; i++)
		if (CheckCollisionRecs(Rect, ArrOfBullets[i].Rect))
			PlanetIsActive[i] = 0;
}

#include "Bullet.h"

Bullet::Bullet()
{
	Velocity = { 0,0 };
}
Bullet::Bullet(Rectangle rect, Texture2D texture)
{
	Velocity = { 0,1 };
	Rect = rect;
	Texture = texture;
}

void Bullet::Draw()
{
	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, 1, WHITE);
}
void Bullet::MoveBullet(Vector2 Direction)
{
	Rect.y -= Direction.y;
}

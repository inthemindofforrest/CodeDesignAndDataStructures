#include "Bullet.h"

Bullet::Bullet()
{
	isActive = false;
}
Bullet::Bullet(Rectangle rect, Texture2D texture)
{
	Rect = rect;
	Texture = texture;
	isActive = false;
}

void Bullet::Draw()
{
	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, .1f, WHITE);
}
void Bullet::MoveBullet(Vector2 Direction)
{
	Rect.y -= Direction.y;
}

void Bullet::Update()
{
	if (isActive)
	{
		Draw();
		MoveBullet({ 0,2 });
	}
}

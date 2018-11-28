#include "Enemy.h"

ENEMY::ENEMY() {}

ENEMY::ENEMY(Texture2D texture, Rectangle rect)
{
	Texture = texture;
	Rect = rect;
}

bool ENEMY::IsClicked()
{
	if (CheckCollisionPointRec({ (float)GetMouseX(), (float)GetMouseY() }, Rect) &&
		IsMouseButtonDown(0))
	{
		return true;
	}
	return false;
}

void ENEMY::Update()
{
	DrawTexture(Texture, (int)Rect.x, (int)Rect.y, BLUE);
}

Vector2 ENEMY::GetPosition()
{
	return { (float)Rect.x, (float)Rect.y };
}
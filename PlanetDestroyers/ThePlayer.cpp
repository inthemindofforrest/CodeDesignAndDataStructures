#include "ThePlayer.h"


Player::Player()
{
}
Player::Player(Rectangle rect, Texture2D texture)
{
	Rect = rect;
	Texture = texture;
}

void Player::Draw()
{
	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, .1f, WHITE);
}
void Player::MovePlayer(Vector2 Direction)
{
	if (IsKeyDown(KEY_A) && Rect.x > 0)
	{
		Rect.x -= Direction.x;
	}
	if (IsKeyDown(KEY_D) && Rect.x < GetScreenWidth() - Texture.width / 10)
	{
		Rect.x += Direction.x;
	}
}

void Player::Update(std::vector<Bullet>  BulletsAreActive)
{
	Draw();
	MovePlayer({ 4,0 });
}

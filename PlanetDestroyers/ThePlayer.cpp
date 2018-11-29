#include "ThePlayer.h"


Player::Player()
{
	Velocity = { 0,10 };
}
Player::Player(Rectangle rect, Texture2D texture)
{
	Velocity = { 0,10 };
	Rect = rect;
	Texture = texture;
}

void Player::Draw()
{
	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, .1f, WHITE);
}
void Player::MovePlayer(Vector2 Direction)
{
	if (IsKeyDown(KEY_A))
	{
		Rect.x -= Direction.x;
	}
	if (IsKeyDown(KEY_D))
	{
		Rect.x += Direction.x;
	}
}

void Player::Update(std::vector<Bullet>  BulletsAreActive)
{
	Draw();
	MovePlayer({ 3,0 });
}

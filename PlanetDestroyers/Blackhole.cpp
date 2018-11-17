#include "Blackhole.h"

BlackHole::BlackHole(){}

BlackHole::BlackHole(Rectangle rect, Texture2D texture)
{
	Rect = rect;
	Texture = texture;
	IsActive = false;
}

void BlackHole::Draw()
{
	if(IsActive)
		DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, .1f, WHITE);
}


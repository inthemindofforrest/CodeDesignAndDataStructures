#include "Button.h"

void Button::Draw(int Size)
{
	int FontSize = 12;

	DrawTextureEx(Texture, { Rect.x, Rect.y }, 0, Size, WHITE);
	DrawText(Name.c_str(), (Rect.x + (Rect.width / 2)) -
		(MeasureText(Name.c_str(), FontSize) / 2),
		Rect.y + (Rect.height / 2) - (FontSize / 2), FontSize, BLACK);
}

Button::Button(std::string name, Rectangle rect, Texture2D texture)
{
	Name = name;
	Rect = rect;
	Texture = texture;
}
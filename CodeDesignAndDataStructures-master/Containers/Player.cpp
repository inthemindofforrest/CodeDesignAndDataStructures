#include "SpellCaster.h"

SPELLS::SPELLS()
{

}

SPELLS::SPELLS(Texture2D texture, SpellTypes SpellName)
{
	Texture = texture;
	Rect = { 0, 0, (float)Texture.width, (float)Texture.height };
	SpellType = SpellName;
}

void SPELLS::Update(Vector2 Position)
{
	switch (SpellType)
	{
	case _Water:
		SpellColor = BLUE;
		break;
	case _Fire:
		SpellColor = RED;
		break;
	case _Earth:
		SpellColor = GREEN;
		break;
	case _Lightning:
		SpellColor = YELLOW;
		break;
	default:
		SpellColor = WHITE;
		break;
	}
	DrawTexture(Texture, (float)Position.x, (float)Position.y, SpellColor);
}

SpellTypes SPELLS::CurrentSpellType()
{
	return SpellType;
}

#pragma once
#include "raylib.h"

enum SpellTypes { _Water, _Fire, _Earth, _Lightning };

class SPELLS
{
	Texture2D Texture;
	Rectangle Rect;
	SpellTypes SpellType;
	Color SpellColor;

public:
	SPELLS();
	SPELLS(Texture2D texture, SpellTypes SpellName);

	void Update(Vector2 Position);
	SpellTypes CurrentSpellType();
};
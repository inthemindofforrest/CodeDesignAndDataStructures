#pragma once
#include "raylib.h"
#include "Queue.h"
#include "tStack.h"

class PLAYER
{
	bool Reverse;
	Texture2D Texture;
	Rectangle Rect;
	tQueue<Vector2> PositionQueue;
	tStack<Vector2> PrevPositionStack;

public:

	PLAYER();
	PLAYER(Texture2D texture, Rectangle rect);

	void AddToQueue(Vector2 posistion);
	void Update();
	void SelectEnemy(Vector2 EnemyPosition);
};
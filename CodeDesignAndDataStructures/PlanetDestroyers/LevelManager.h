#pragma once
#include "Button.h"

class LevelManager
{
	LevelManager();
	~LevelManager();
	LevelManager(LevelManager const&);
	void operator=(LevelManager const&);
	std::vector<Button> LevelButtons;
public:
	void Update();
	static LevelManager& GetInstance();
	void PushButton(Button& newButton);
	void PullButton();
	Rectangle GetButtonRect(int BNumber);
	size_t AmountOfButtons();
};
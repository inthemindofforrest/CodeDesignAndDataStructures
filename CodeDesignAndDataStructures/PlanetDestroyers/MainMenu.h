#pragma once
#include "Button.h"

	class MainMenuScreen
	{
		MainMenuScreen();
		~MainMenuScreen();
		MainMenuScreen(MainMenuScreen const&);
		void operator=(MainMenuScreen const&);
		std::vector<Button> MainMenuButtons;
	public:
		void Update();
		static MainMenuScreen& GetInstance();
		void PushButton(Button& newButton);
		void PullButton();
		Rectangle GetButtonRect(int BNumber);
		size_t AmountOfButtons();
	};

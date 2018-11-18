#include "MainMenu.h"
#include "GameStates.h"

MainMenuScreen::MainMenuScreen()
{
	Texture2D BasicButton = LoadTexture("Blank.png");
	PushButton(*new Button("Play", { ((float)GetScreenWidth() / 2) - BasicButton.width / 2,(((float)GetScreenHeight() / 10) * 2) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
	PushButton(*new Button("Options", { ((float)GetScreenWidth() / 2) - BasicButton.width / 2,(((float)GetScreenHeight() / 10) * 5) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
	PushButton(*new Button("Quit", { ((float)GetScreenWidth() / 2) - BasicButton.width / 2,(((float)GetScreenHeight() / 10) * 8) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
	PushButton(*new Button("Option 1", { ((float)GetScreenWidth() / 2) - BasicButton.width / 2,(((float)GetScreenHeight() / 10) * 2) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
	PushButton(*new Button("Option 1", { ((float)GetScreenWidth() / 2) - BasicButton.width / 2,(((float)GetScreenHeight() / 10) * 5) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
	PushButton(*new Button("Back", { ((float)GetScreenWidth() / 2) - BasicButton.width / 2,(((float)GetScreenHeight() / 10) * 8) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
}
MainMenuScreen::~MainMenuScreen()
{
	for (auto i = 0; i < MainMenuButtons.size(); i++)
	{
		PullButton();
	}
}
MainMenuScreen::MainMenuScreen(MainMenuScreen const&) {}
void MainMenuScreen::operator=(MainMenuScreen const&) {}


void MainMenuScreen::Update()
{
	
	for (int i = 0; i < AmountOfButtons(); i++)
	{
		if (GameState::GetInstance().getState() == 2 && i == 0)
		{
			i += 2;
			continue;
		}
		else if (GameState::GetInstance().getState() != 2 && i >= 3)
			break;

		MainMenuButtons[i].Draw(1);

		if (IsMouseButtonPressed(0) && CheckCollisionPointRec(GetMousePosition(), GetButtonRect(i)))
		{
			switch (i)
			{
			case 0://LevelSelection -> Play
				GameState::GetInstance().setState(1);
				break;
			case 1://Controls
				GameState::GetInstance().setState(2);
				break;
			case 2://Exit
				GameState::GetInstance().setState(3);
				break;
			case 3:
				//Do Something
				break;
			case 4:
				//Do Something
				break;
			case 5:
				GameState::GetInstance().setState(0);
				break;
			default:
				break;
			}
		}
	}
}
MainMenuScreen& MainMenuScreen::GetInstance()
{
	static MainMenuScreen Instance;
	return Instance;
}
void MainMenuScreen::PushButton(Button &newButton)
{
	MainMenuButtons.push_back(newButton);
}
void MainMenuScreen::PullButton()
{
	MainMenuButtons.pop_back();
}
Rectangle MainMenuScreen::GetButtonRect(int BNumber)
{
	return MainMenuButtons.at(BNumber).Rect;
}
size_t MainMenuScreen::AmountOfButtons()
{
	return MainMenuButtons.size();
}
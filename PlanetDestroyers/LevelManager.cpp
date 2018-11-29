#include "LevelManager.h"
#include "GameStates.h"

LevelManager::LevelManager()
{
	Texture2D BasicButton = LoadTexture("Blank.png");
	PushButton(*new Button("Back", { ((float)GetScreenWidth() / 2) - BasicButton.width / 2,(((float)GetScreenHeight() / 10) * 8) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
	PushButton(*new Button("Easy", { (((float)GetScreenWidth() / 10) * 3) - BasicButton.width / 2,((float)GetScreenHeight() / 2) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
	PushButton(*new Button("Hard", { (((float)GetScreenWidth() / 10) * 7) - BasicButton.width / 2,((float)GetScreenHeight() / 2) - BasicButton.height / 2,(float)BasicButton.width ,(float)BasicButton.height }, LoadTexture("Blank.png")));
}
LevelManager::~LevelManager(){}
LevelManager::LevelManager(LevelManager const&) {}
void LevelManager::operator=(LevelManager const&) {}


void LevelManager::Update()
{
	for (int i = 0; i < AmountOfButtons(); i++)
	{
		LevelButtons[i].Draw(1);

		if (IsMouseButtonPressed(0) && CheckCollisionPointRec(GetMousePosition(), GetButtonRect(i)))
		{
			switch (i)
			{
			case 0:
				GameState::GetInstance().setState(0);
				break;
			case 1:
				GameState::GetInstance().setState(4);
				break;
			case 2:
				GameState::GetInstance().setState(5);
				break;
			default:
				break;
			}
		}
	}
}
LevelManager& LevelManager::GetInstance()
{
	static LevelManager Instance;
	return Instance;
}
void LevelManager::PushButton(Button& newButton)
{
	LevelButtons.push_back(newButton);
}
void LevelManager::PullButton()
{
	LevelButtons.pop_back();
}
Rectangle LevelManager::GetButtonRect(int BNumber)
{
	return LevelButtons[BNumber].Rect;
}
size_t LevelManager::AmountOfButtons()
{
	return LevelButtons.size();
}
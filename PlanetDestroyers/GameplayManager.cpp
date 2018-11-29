#include "GameplayManager.h"

GameplayManager::GameplayManager() {}
GameplayManager::~GameplayManager() {}
GameplayManager::GameplayManager(GameplayManager const&) {}
void GameplayManager::operator=(GameplayManager const&) {}

GameplayManager& GameplayManager::GetInstance()
{
	static GameplayManager Instance;
	return Instance;
}

void GameplayManager::Update(int Difficulty)
{
	static float Timer = 0;

	BackgroundPlanet->Draw(10.0f);
	DrawText(std::to_string(Score).c_str(), (GetScreenWidth() / 2) -
		(MeasureText(std::to_string(Score).c_str(), 25) / 2),
		(GetScreenHeight() / 10) * 1, 25, WHITE);


	for (int i = 0; i < ArrOfPlanets.size(); i++)
	{
		if (ArrOfPlanets[i].isActive)
		{
			ArrOfPlanets[i].Update();

			if (ArrOfPlanets[i].isActive && ArrOfPlanets[i].Rect.y > GetScreenHeight())
			{
				GameState::GetInstance().setState(3);
			}
			for (int j = 0; j < ArrOfBullets.size(); j++)
			{
				if (CheckCollisionRecs(ArrOfPlanets[i].Rect, ArrOfBullets[j].Rect) && ArrOfBullets[j].isActive)
				{
					ArrOfPlanets[i].isActive = false;
					Score += 1;
				}
			}
		}
	}
	for (int i = 0; i < ArrOfBullets.size(); i++)
	{
		if (ArrOfBullets[i].isActive)
		{
			ArrOfBullets[i].Update();

			if (ArrOfBullets[i].isActive && ArrOfBullets[i].Rect.y < 0)
			{
				ArrOfBullets[i].isActive = false;
			}

		}
	}
	if(Difficulty == 0)
		Timer += GetFrameTime();
	else
		Timer += GetFrameTime() * 2;
	if (Timer >= 1)
	{
		for (int i = 0; i < ArrOfPlanets.size(); i++)
		{
			if (!ArrOfPlanets[i].isActive)
			{
				ArrOfPlanets[i].isActive = true;

				ArrOfPlanets[i].Rect = { (float)(rand() % (GetScreenWidth() - ArrOfPlanets[i].Texture.width)),-10,(float)ArrOfPlanets[i].Rect.width, (float)ArrOfPlanets[i].Rect.height };

				Timer = 0;
				break;
			}
		}
	}

	MainPlayer.Update(ArrOfBullets);

	if (IsKeyPressed(KEY_SPACE))
	{
		for (int i = 0; i < ArrOfBullets.size(); i++)
		{
			if (!ArrOfBullets[i].isActive)
			{
				ArrOfBullets[i].isActive = true;
				ArrOfBullets[i].Rect.x = (float)MainPlayer.Rect.x;
				ArrOfBullets[i].Rect.y = (float)MainPlayer.Rect.y;
				break;
			}
		}
	}

}

void GameplayManager::InitPlanets(int TotalPool)
{
	Texture2D PlanetTexture = LoadTexture("Planet.png");
	Texture2D BulletTexture = LoadTexture("Bullet.png");
	Texture2D PlayerTexture = LoadTexture("Player.png");
	Planet TempPlanet({ 0, 0, (float)PlanetTexture.width / 2, (float)PlanetTexture.height / 2}, PlanetTexture);
	Bullet TempBullet({ 0, 0, (float)BulletTexture.width / 2, (float)BulletTexture.height / 2}, BulletTexture);

	for (int i = 0; i < TotalPool; i++)
	{
		ArrOfPlanets.push_back(TempPlanet);
		ArrOfBullets.push_back(TempBullet);
	}

	MainPlayer.Rect = { (float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 20) * 18, 10, 30 };
	MainPlayer.Texture = PlayerTexture;

	BackgroundPlanet = new Planet({(float)(GetScreenWidth() / 2 - (PlanetTexture.width / 2) * 10),(float)(GetScreenHeight() - ((PlanetTexture.height / 10 )* 10) * 2),(float)(PlanetTexture.width * 5),(float)(PlanetTexture.height * 5)}, PlanetTexture);
}
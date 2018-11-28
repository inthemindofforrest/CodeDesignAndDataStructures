#pragma once
enum States { MainMenu, LevelSelection, Controls, GameOver, Level1, Level2 };
class GameState
{
private:
	GameState();
	GameState(GameState const&);  // prevents external use
	void operator=(GameState const&); // prevents external use
	int state;

public:
	int getState();
	void setState(int newState);
	static GameState& GetInstance();
	~GameState();
};
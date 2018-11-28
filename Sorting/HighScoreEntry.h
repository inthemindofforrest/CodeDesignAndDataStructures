#pragma once
#include <iostream>
class HighScoreEntry
{
public:
	std::string Name;
	int Score;
	int Level;

	HighScoreEntry();
	HighScoreEntry(std::string name, int score, int level);
	~HighScoreEntry();

	bool operator>(HighScoreEntry &Entry);
	bool operator<(HighScoreEntry &Entry);
	bool operator>=(HighScoreEntry &Entry);
	bool operator<=(HighScoreEntry &Entry);
	HighScoreEntry& operator=(HighScoreEntry &Entry);
	bool operator==(HighScoreEntry &Entry);
};
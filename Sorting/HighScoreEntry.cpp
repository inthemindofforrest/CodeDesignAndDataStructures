#include "HighScoreEntry.h"

HighScoreEntry::HighScoreEntry()
{

}

HighScoreEntry::HighScoreEntry(std::string name, int score, int level)
{
	Name = name;
	Score = score;
	Level = level;
}

HighScoreEntry::~HighScoreEntry()
{

}

bool HighScoreEntry::operator>(HighScoreEntry &Entry) {
	return (Score > Entry.Score);
}

bool HighScoreEntry::operator<(HighScoreEntry &Entry) {
	return (Score < Entry.Score);
}
bool HighScoreEntry::operator>=(HighScoreEntry &Entry) {
	return (Score >= Entry.Score);
}

bool HighScoreEntry::operator<=(HighScoreEntry &Entry) {
	return (Score <= Entry.Score);
}

bool HighScoreEntry::operator==(HighScoreEntry &Entry) {
	return (Score == Entry.Score);
}

HighScoreEntry& HighScoreEntry::operator=(HighScoreEntry &Entry)
{
	Name = Entry.Name;
	Level = Entry.Level;
	Score = Entry.Score;
	return Entry;
}
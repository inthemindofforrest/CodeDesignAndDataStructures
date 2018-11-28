#pragma once
#include "HighScoreEntry.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class HighScoreTable
{
	//Name, Score, Level
public:
	std::vector<HighScoreEntry> hsVector;
	std::vector<HighScoreEntry> topNNScores(int TopRows);
	bool pruneBottomNNScores(int bottomRows);

	HighScoreTable();
	HighScoreTable(std::string fileName);
	~HighScoreTable();

	void BubbleSort(bool Decending);
	void InsertionSort();
	void LocalMergeSort();
};
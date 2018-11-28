#include "HighScoreTable.h"
#include "MergeSort.h"
#include <vector>
#include <iostream>

int main() {
	//Instantiate and initialize the whole highscore table
	HighScoreTable hst("highscores.txt");
	//std::cout << hst.hsVector.at(hst.hsVector.size - 1).Name << std::endl;


	hst.LocalMergeSort();

	//prune the bottom 3 scores from the table
	hst.pruneBottomNNScores(3);

	//retrieve the top 10 scores
	std::vector<HighScoreEntry> topScores = hst.topNNScores(10);
	//todo: cycle through the scores and output them


	return 0;
}
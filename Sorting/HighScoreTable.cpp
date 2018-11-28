#include "HighScoreTable.h"
#include "MergeSort.h"

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	//BubbleSort();
	//InsertionSort();
	if (hsVector.size() > bottomRows)
	{
		for (int i = 0; i < bottomRows; i++)
			hsVector.pop_back();
		return true;
	}
	else
	{
		for (int i = 0; i < hsVector.size(); i++)
			hsVector.pop_back();
	}
	return false;
}

std::vector<HighScoreEntry> HighScoreTable::topNNScores(int TopRows)
{
	std::vector<HighScoreEntry> Temp;
	HighScoreEntry ScoreTemp;
	for (size_t i = hsVector.size() - 1; i > hsVector.size() - TopRows - 1; i--)
	{
		ScoreTemp.Level = hsVector[i].Level;
		ScoreTemp.Name = hsVector[i].Name;
		ScoreTemp.Score = hsVector[i].Score;
		Temp.push_back(ScoreTemp);
	}

	return Temp;
}

HighScoreTable::HighScoreTable()
{

}

HighScoreTable::HighScoreTable(std::string fileName)
{

	std::string CurrentElement;
	std::string Line;
	std::fstream file(fileName, std::ios::in);
	int InputNumber = 0;


	while (getline(file, Line))
	{
		HighScoreEntry Temp;
		for (int i = 0; (i <= Line.length()); i++)
		{
			if (Line[i] == ',' || (i == Line.length()))
			{
				switch (InputNumber)
				{
				case 0:
					Temp.Name = CurrentElement;
					break;
				case 1:
					Temp.Score = stoi(CurrentElement);
					break;
				case 2:
					Temp.Level = stoi(CurrentElement);
					InputNumber = -1;

					hsVector.push_back(Temp);
					break;
				default:
					break;
				}
				CurrentElement.clear();
				InputNumber++;
			}
			else
			{
				if (Line[i] != '\n' || Line[i] != -1)
					CurrentElement += Line[i];
			}
		}
	}
	file.flush();
	file.close();

	//BubbleSort(false);
	//InsertionSort();
	//MergeSort(hsVector, 0, hsVector.size());
}

HighScoreTable::~HighScoreTable()
{

}
void HighScoreTable::BubbleSort(bool Decending)
{
	int op = 0;
	for (size_t m = 0; m < hsVector.size() - 1; m++)
		for (size_t j = hsVector.size() - 1; j > m; j--)
		{
			if ((hsVector[j].Score < hsVector[m].Score * Decending) + (hsVector[j].Score > hsVector[m].Score * !Decending))
			{
				HighScoreEntry Temp = hsVector[m];
				hsVector[m] = hsVector[j];
				hsVector[j] = Temp;
			}
			op++;
		}
	std::cout << "Bubble Sort: " << op << std::endl;
}

void HighScoreTable::InsertionSort()
{
	int op = 0;
	for (int i = 1; i < hsVector.size(); i++)
	{
		HighScoreEntry Temp = hsVector[i];
		int Below = i - 2;
		for (; Below >= 0; Below--)
		{
			if (hsVector[Below].Score < hsVector[i].Score && hsVector[Below + 1].Score >= hsVector[i].Score)
			{
				for (int Move = i; Move > Below + 1; Move--)
				{
					op++;
					hsVector[Move] = hsVector[Move - 1];
				}
				hsVector[Below + 1] = Temp;
			}
			if (hsVector[0].Score >= hsVector[i].Score)
			{
				for (int Move = i; Move > 0; Move--)
				{
					op++;
					hsVector[Move] = hsVector[Move - 1];
				}
				hsVector[0] = Temp;
			}

		}
	}
	std::cout << op << std::endl;
}

void HighScoreTable::LocalMergeSort()
{
	MergeSort(&hsVector, 0, hsVector.size() - 1);
}


//bool HighScoreTable::SaveBackToFile(std::string fileName)
//{
//	std::string CurrentElement;
//	std::string Line;
//	std::fstream file(fileName, std::ios::out);
//	int InputNumber = 0;
//
//}
#include <vector>
#include <iostream>

void BubbleSort(bool Decending, std::vector<int> hsVector)
{
	for (size_t m = 0; m < hsVector.size() - 1; m++)
		for (size_t j = hsVector.size() - 1; j > m; j--)
			if ((hsVector[j] < hsVector[m] * Decending) + (hsVector[j] > hsVector[m] * !Decending))
			{
				int Temp = hsVector[m];
				hsVector[m] = hsVector[j];
				hsVector[j] = Temp;
			}
}
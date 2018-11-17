#include <vector>
#include <iostream>

void InsertionSort(std::vector<int> hsVector)
{
	for (int i = 1; i < hsVector.size(); i++)
	{
		int Temp = hsVector[i];
		int Below = i - 2;
		for (; Below >= 0; Below--)
		{
			if (hsVector[Below] < hsVector[i] && hsVector[Below + 1] >= hsVector[i])
			{
				for (int Move = i; Move > Below + 1; Move--)
				{
					hsVector[Move] = hsVector[Move - 1];
				}
				hsVector[Below + 1] = Temp;
			}
			if (hsVector[0] >= hsVector[i])
			{
				for (int Move = i; Move > 0; Move--)
				{
					hsVector[Move] = hsVector[Move - 1];
				}
				hsVector[0] = Temp;
			}

		}
	}
}
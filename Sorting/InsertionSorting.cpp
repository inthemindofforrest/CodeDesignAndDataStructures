void InsertionSort()
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
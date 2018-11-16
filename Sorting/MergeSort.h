#pragma once
template<typename T>
void Merge(T * arr, size_t Beginning, size_t Middle, size_t End)
{
	size_t LeftEnd = Middle - Beginning + 1;
	size_t RightEnd = End - Middle;

	T * LeftArray = new T[LeftEnd];
	T * RightArray = new T[RightEnd];

	for (size_t i = 0; i < LeftEnd; i++)
	{
		LeftArray[i] = arr[Beginning + i];
	}
	for (size_t j = 0; j < RightEnd; j++)
	{
		RightArray[j] = arr[Middle + j + 1];
	}

	size_t j = 0;
	size_t i = 0;

	for (int k = Beginning; k <= End; k++)
	{
		if (j >= RightEnd || (i < LeftEnd && LeftArray[i] <= RightArray[j]))
		{
			arr[k] = LeftArray[i];
			i++;
		}
		else
		{
			arr[k] = RightArray[j];
			j++;
		}
	}
	delete LeftArray;
	delete RightArray;
}

template<typename T>
void MergeSort(T * arr, size_t Beginning, size_t End)
{
	if (Beginning < End)
	{
		size_t Middle = (Beginning + End) / 2;
		MergeSort(arr, Beginning, Middle);
		MergeSort(arr, Middle + 1, End);
		Merge(arr, Beginning, Middle, End);
	}
}

template<typename T>
void Merge(std::vector<T> * arr, size_t Beginning, size_t Middle, size_t End)
{
	size_t LeftEnd = Middle - Beginning + 1;
	size_t RightEnd = End - Middle;

	std::vector<T> LeftArray;
	LeftArray.reserve(LeftEnd);
	std::vector<T> RightArray;
	RightArray.reserve(RightEnd);

	for (size_t i = 0; i < LeftEnd; i++)
	{
		//LeftArray->at(i) = arr[Beginning + i];
		LeftArray.push_back(arr->at(Beginning + i));
	}
	for (size_t j = 0; j < RightEnd; j++)
	{
		//RightArray->at(i) = arr[Middle + j + 1];
		RightArray.push_back(arr->at(Middle + j + 1));
	}

	size_t j = 0;
	size_t i = 0;

	for (size_t k = Beginning; k <= End; k++)
	{
		if (j >= RightEnd || (i < LeftEnd && LeftArray[i] <= RightArray[j]))
		{
			/*arr[k] = LeftArray[i];*/
			arr->at(k) = LeftArray[i];
			i++;
		}
		else
		{
			//arr[k] = RightArray[j];
			arr->at(k) = RightArray[j];
			j++;
		}
	}
}

template<typename T>
void MergeSort(std::vector<T> * arr, size_t Beginning, size_t End)
{
	if (Beginning < End)
	{
		size_t Middle = (Beginning + End) / 2;
		MergeSort(arr, Beginning, Middle);
		MergeSort(arr, Middle + 1, End);
		Merge(arr, Beginning, Middle, End);
	}
}
#pragma once

template <typename T>
class TVECTOR
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	TVECTOR()// initializes the vector's default values
	{
		arrCapacity = 1;
		arr = new T[arrCapacity]();
		arrSize = 0;

	}
	~TVECTOR()                         // destroys the underlying array
	{
		delete[] arr;
		//delete * arr;
	}

	T *data()                          // returns a pointer to the underlying array
	{
		return arr;
	}

	void reserve(size_t newCapacity)   // resizes the vector to at least this many elements
	{
		T *temp = new T[newCapacity]();
		for (size_t i = 0; i <= arrSize; i++)
		{
			if (i > newCapacity)
				break;
			temp[i] = arr[i];
		}

		arrCapacity = newCapacity;
		arr = temp;
	}

	void push_back(const T &value)     // adds an element to the end of the vector
	{
		if ((arrCapacity) == arrSize)
		{
			reserve(arrCapacity * GROWTH_FACTOR);
		}

		arr[arrSize] = value;
		arrSize++;
	}
	void pop_back()                    // drops the last element of the vector
	{
		arrSize--;
	}

	//void push_front(const T &value)     // adds an element to the end of the vector
	//{
	//	if ((arrCapacity) == arrSize)
	//	{
	//		reserve(arrCapacity * GROWTH_FACTOR);
	//	}

	//	arrSize++;

	//	for (size_t i = arrSize - 1; i > 0; i--)
	//		arr[i] = arr[i - 1];
	//	arr[0] = value;
	//}

	T &at(size_t index)                // returns the element at the given element
	{
		return arr[index];
	}

	size_t size() const                // returns current number of elements
	{
		return arrSize;
	}
	size_t capacity() const            // returns maximum number of elements we can store
	{
		return arrCapacity;
	}


	TVECTOR(const TVECTOR &vec)
	{
		arr = new T[vec.arrCapacity]();
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;

		for (size_t i = 0; i < arrCapacity; i++)
		{
			arr[i] = vec.arr[i];
		}
	}

	TVECTOR& operator=(const TVECTOR &vec)
	{
		delete[] arr;
		arr = new T[vec.arrCapacity]();
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;

		for (size_t i = 0; i < arrCapacity; i++)
		{
			arr[i] = vec[i];
		}
	}

	T& operator[] (size_t index)
	{
		return at(index);
	}


	bool empty()         // Returns true if the vector contains no elements.
	{
		return !arrSize;
	}
	void shrink_to_fit() // Resizes the vector's capacity to match its size.
	{
		T temp = new T[arrSize];
		for (size_t i = 0; i < arrSize; i++)
			temp[i] = arr[i];

		delete[] arr;

		arr = temp;
		arrCapacity = arrSize;
	}
	void clear()         // Empties the vector (all elements are destroyed in this process)
	{
		arrCapacity = 1;
		arrSize = 0;

		T temp = new T[arrCapacity];

		delete[] arr;

		arr = temp;
	}



};



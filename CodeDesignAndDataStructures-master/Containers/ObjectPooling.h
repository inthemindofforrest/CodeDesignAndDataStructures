#pragma once

template<typename T>
class tObjectPool
{

	T* pool;                            // all objects stored in the pool                  
	size_t TotalCapacity;
public:
	bool* free; // indicates whether an object is available
	tObjectPool()                       // default initializes the object pool
	{

	}
	tObjectPool(size_t initialCapacity) // initializes the pool to have a set number of objects
	{
		TotalCapacity = initialCapacity;

		pool = new T[initialCapacity];
		free = new bool[initialCapacity];

		for (int i = 0; i < initialCapacity; i++)
			free[i] = true;
	}
	~tObjectPool()                      // destroys all objects
	{

	}

	T* retrieve(size_t Index)                      // returns a pointer to an object that will be used (returns null if none available)
	{
		if (free[Index] == false)
			return &pool[Index];
		return nullptr;
	}
	void recycle(T* obj)               // accepts a pointer that can be used in the future
	{
		for (int i = 0; i < TotalCapacity; i++)
			if (free[i] == true)
			{
				free[i] = false;
				pool[i] = *obj;
				return;
			}
	}
	void DeactivateIndex(size_t Index)               // accepts a pointer that can be used in the future
	{
		free[Index] = true;
	}
	size_t capacity()                  // returns the total number of objects that this pool can provide
	{
		return TotalCapacity;
	}
};
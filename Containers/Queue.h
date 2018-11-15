#pragma once
typedef bool boo;
#include "tVector.h"

template <typename T>
class tQueue
{
	TVECTOR<T> vec;                       // contains the data for a queue

public:
	tQueue() {}                        // default initializes the queue

	tQueue(size_t count, const T& value) // constructs a queue with the given number of elements 
	{
		for (size_t i = 0; i < count; i++)
			vec.push_back(value);
	}
	// each element is initialized by copying the given value

	void push(const T& value)            // adds an element to the top of the Queue
	{
		vec.push_front(value);
	}
	void pop()                           // drops the top-most element of the Queue
	{
		if (vec.size() > 0)
			vec.pop_back();
	}

	const T& front() const                           // returns the front-most element
	{
		vec[0];
	}
	const T& back() const                            // returns the back-most element
	{
		vec[vec.arrSize - 1];
	}

	size_t size() const                  // returns current number of elements
	{
		return vec.size();
	}

	T& operator[] (size_t index)
	{
		return vec[index];
	}

	boo empty() const
	{
		return vec.empty();
	}
};
#pragma once
#include "tVector.h"
typedef bool boo;

template <typename T>
class tStack
{
	TVECTOR<T> vec;                     // contains the data for a stack

public:
	tStack() {}                        // initializes the stack's default values


	void push(const T& value)          // adds an element to the top of the Stack
	{
		vec.push_back(value);
	}
	void pop()                         // drops the top-most element of the Stack
	{
		if (vec.size() > 0)
			vec.pop_back();
	}

	const T& top() const                          // returns the top-most element at the given element
	{
		return vec[vec.size() - 1];
	}

	size_t size() const                // returns current number of elements
	{
		return vec.size();
	}

	boo empty() const
	{
		return vec.empty();
	}

	T& operator[] (size_t index)
	{
		return vec[index];
	}
};



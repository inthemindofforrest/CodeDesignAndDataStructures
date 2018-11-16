#include "ForwardLinkedList.h"
#include <iostream>

int main()
{
	tForwardList<int> List;
	List.push_front(3);
	List.push_front(4);
	tForwardList<int> newerList(List);
	newerList.pop_front();
	tForwardList<int> newList = List;

	for (auto it = List.begin(); it != List.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	return 0;
}
#include "ForwardLinkedList.h"
#include <iostream>

int main()
{
	tForwardList<int> List;
	List.push_front(6);
	List.push_front(5);
	List.push_front(4);
	List.push_front(3);
	List.push_front(2);
	List.push_front(1);

	List.remove(5);

	List.resize(8, 0);

	List.resize(3, 0);

	for (auto it = List.begin(); it != List.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	return 0;
}
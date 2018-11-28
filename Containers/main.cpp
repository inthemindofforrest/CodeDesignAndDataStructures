#include "ForwardLinkedList.h"
#include <iostream>
#include "Queue.h"

int main()
{
	/*tForwardList<int> List;
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
	}*/

	tQueue<int> List;
	List.push(6);
	List.push(5);
	List.push(4);
	List.push(3);
	List.push(2);
	List.push(1);


	List.pop();

	for (int it = 0; it < List.size(); ++it)
	{
		std::cout << List[it] << std::endl;
	}

	return 0;
}
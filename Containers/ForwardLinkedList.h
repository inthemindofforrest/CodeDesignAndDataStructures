#pragma once

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList()                 // default constructor
	{
		head = nullptr;
	}
	~tForwardList()                // destructor
	{

	}

	void push_front(const T& val)  // adds element to front (i.e. head)
	{
		Node * TempNode = new Node{ val, head };
		head = TempNode;
	}
	void pop_front()               // removes element from front
	{
		Node * Temp = (*head).next;
		delete head;
		head = Temp;
	}

	T& front()                     // returns the element at the head
	{
		return (*head).data;
	}
	const T& front() const         // returns the element at the head (const)
	{
		return (*head).data;
	}

	void remove(const T& val)      // removes all elements equal to the given value
	{
		/*Node * PastNode = nullptr;
		Node * CurrentNode = nullptr;
		Node * NextNode = nullptr;*/
		Node * PreviousNode = nullptr;
		Node * NextNode = nullptr;
		for (Node * CurrentNode = head; CurrentNode != NULL; CurrentNode = CurrentNode->next)
		{
			/*	if (CurrentNode->next != nullptr)
			NextNode = CurrentNode->next;

			if (CurrentNode->data == val)
			{
			if (PastNode != nullptr)
			{
			if (NextNode != nullptr)
			PastNode->next = NextNode;
			else
			PastNode->next = nullptr;
			}
			else
			if (NextNode != nullptr)
			head = NextNode;
			else
			head = nullptr;
			PTRCurrent = CurrentNode->next;
			delete CurrentNode;
			CurrentNode = PTRCurrent;
			}
			else
			{
			PastNode = CurrentNode;
			if(NextNode->data != val)
			while (NextNode->data != val)
			{
			PTRCurrent = NextNode->next;
			delete NextNode;
			NextNode = PTRCurrent;
			}
			else
			{
			CurrentNode = NextNode;
			}
			}*/
			if (head->data == val)
			{
				//if the head == the value, use pop_front to remove the head. Then set current to the next
				pop_front();
				CurrentNode = head;
			}
			else
			{
				PreviousNode = CurrentNode;
				if (CurrentNode->next != nullptr)
					NextNode = CurrentNode->next;
				else
					return;


				if (NextNode->data == val)
				{
					CurrentNode = NextNode;
					NextNode = CurrentNode->next;
					delete NextNode;
					continue;
				}

			}
		}
	}
};
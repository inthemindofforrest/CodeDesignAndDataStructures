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
	tForwardList();                 // default constructor
	~tForwardList(){}                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value


	void clear();
	bool empty() const;
	void resize(size_t newSize);

	tForwardList(const tForwardList& other);
	tForwardList& operator=(const tForwardList &rhs);


	// Add this to your declaration
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++()                     // pre-increment (returns a reference to this iterator after it is incremented)
		{
			cur = cur->next;
			return (*this);
		}
		iterator operator++(int)                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
		{
			Node * Temp = cur;
			++cur;
			return Temp;
		}
	};

	iterator begin()
	{
		return head;
	}
	iterator end()
	{
		Node * cur = head;
		while (cur->next != nullptr)
		{
			cur = cur.next;
		}
		return (*this);
	}

};

template<typename T>
tForwardList<T>::tForwardList()
{
	head = nullptr;
}

template<typename T>
void tForwardList<T>::push_front(const T& val)
{
	Node * TempNode = new Node{ val, head };
	head = TempNode;
}

template<typename T>
void tForwardList<T>::pop_front()
{
	Node * Temp = (*head).next;
	delete head;
	head = Temp;
}

template<typename T>
T& tForwardList<T>::front()
{
	return (*head).data;
}

template<typename T>
const T& tForwardList<T>::front() const
{
	return (*head).data;
}

template<typename T>
void tForwardList<T>::remove(const T& val)      // removes all elements equal to the given value
{
	Node * PreviousNode = nullptr;
	Node * NextNode = nullptr;
	for (Node * CurrentNode = head; CurrentNode != NULL; CurrentNode = CurrentNode->next)
	{

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
				delete NextNode;
				NextNode = CurrentNode->next;
				continue;
			}

		}
	}
}

template<typename T>
void tForwardList<T>::clear()
{
	Node * ToBeDestroyed = head;
	Node * CurrentNode = head->next;
	while (CurrentNode != nullptr)
	{
		delete ToBeDestroyed;
		ToBeDestroyed = CurrentNode;
		CurrentNode = CurrentNode->next;
	}
	head = nullptr;
}

template<typename T>
bool tForwardList<T>::empty() const
{
	if (head != nullptr)
		return true;
	return false;
}

template<typename T>//NEED TO FINISH THIS ONE
void tForwardList<T>::resize(size_t newSize)
{

}

template<typename T>
tForwardList<T>::tForwardList(const tForwardList& other)
{
	Node * Temp = other.head->next;//Points within the Other list
	Node * newNode = new Node{ Temp->data, nullptr };//Points within the Current List
	head = new Node{ other.head->data , newNode };
	while (Temp != nullptr)
	{
		Temp = Temp->next;
		if (Temp == nullptr)
			break;
		newNode->next = new Node{ Temp->data, nullptr };
		newNode = newNode->next;
	}
}

template<typename T>
tForwardList<T>& tForwardList<T>::operator=(const tForwardList &rhs)
{
	clear();
	Node * Temp = rhs.head->next;//Points within the rhs list
	Node * newNode = new Node{ Temp->data, nullptr };//Points within the Current List
	head = new Node{ other.head->data , newNode };
	while (Temp != nullptr)
	{
		Temp = Temp->next;
		if (Temp == nullptr)
			break;
		newNode->next = new Node{ Temp->data, nullptr };
		newNode = newNode->next;
	}
}

template<typename T>
T& tForwardList<T>::iterator::operator*() const
{
	return cur;
}

template<typename T>
bool tForwardList<T>::iterator::operator==(const iterator& rhs) const
{
	if (cur == rhs.cur)
		return true;
	return false;
}



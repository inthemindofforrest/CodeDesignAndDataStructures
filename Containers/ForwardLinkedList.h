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
	~tForwardList() {}                // destructor

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	void remove(const T& val);      // removes all elements equal to the given value


	void clear();
	bool empty() const;
	void resize(size_t newSize, T Data);

	tForwardList(const tForwardList& other);
	tForwardList& operator=(const tForwardList &rhs);


	// Add this to your declaration
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator() {}
		iterator(Node * Start)
		{
			cur = Start;
		}

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
			iterator TempIterator;
			TempIterator.cur = cur;

			++cur;
			return TempIterator;
		}
	};

	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr);
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
	Node * CurrentNode = head;
	while (CurrentNode != nullptr)
	{
		if (CurrentNode->data == val)
		{
			Node * TempNextNode = CurrentNode->next;
			CurrentNode->data = head->data;
			pop_front();
			CurrentNode = TempNextNode;
		}
		else
			CurrentNode = CurrentNode->next;
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
void tForwardList<T>::resize(size_t newSize, T Data)
{
	Node * TempNode = head;
	int currentNodes = 0; // Counts how many Nodes are in the list
	while (TempNode->next != nullptr)
	{
		currentNodes++;
		TempNode = TempNode->next;
	}

	if (currentNodes < newSize)
	{
		for (int i = currentNodes + 1; i < newSize; i++)
		{
			push_front(Data);

			Node * CurrentNode = head;
			Node * NextNode = head->next;
			for (int i = 0; i <= currentNodes; i++)
			{
				CurrentNode->data = NextNode->data;
				CurrentNode = NextNode;
				NextNode = NextNode->next;
			}
			CurrentNode->data = Data;
		}
	}
	else
	{
		for (int i = newSize - 1; i < currentNodes; i++)
		{
			pop_front();
		}
	}
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
	head = new Node{ rhs.head->data , newNode };
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
	return cur->data;
}

template<typename T>
bool tForwardList<T>::iterator::operator==(const iterator& rhs) const
{
	if (cur == rhs.cur)
		return true;
	return false;
}

template<typename T>
bool tForwardList<T>::iterator::operator!=(const iterator& rhs) const
{
	if (cur != rhs.cur)
		return true;
	return false;
}

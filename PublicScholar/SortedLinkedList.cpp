#include "SortedLinkedList.h"

template <typename T>
SortedLinkedList<T>::SortedLinkedList() : LinkedList()
{

}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const T& t) : LinkedList(t)
{

}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T>& l) : LinkedList(l)
{

}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
	// base class has got it
}

template <typename T>
void SortedLinkedList<T>::add(const T& t) 
{
	if (_head == NULL) {
		_head = new T(t);
	}
	if ((*_head) > t) {
		prepend(t);
	}
	else {
		_tail->add(t);
	}
}

template <typename T>
void SortedLinkedList<T>::remove(const T& t) 
{
	LinkedList<T> * node = find(t);
	if (node != NULL) {
		node->remove();
	}
}


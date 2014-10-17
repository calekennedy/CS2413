#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
	_head = new T();
	_tail = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const T& t)
{
	_head = new T(t);
	_tail = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& l)
{
	copy(l);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	if (_head) { delete _head;  }
	_head = NULL;
	
	if (_tail) { delete _tail; }
	_tail = NULL;
}

// class methods
template <typename T>
T& LinkedList<T>::operator[] (int k)
{
	// 0 indexed and the last node is a NULL pointer.
	// length() returns the number of elements in the list
	if (k > (length()-1)) {
		throw new LinkedListOutOfBoundsException();
	}

	if (k == 0) {
		return (*_head);
	}
	else {
		return (*_tail)[k - 1];
	}
}
template <typename T>
void LinkedList<T>::operator= (const LinkedList<T>& l)
{
	copy(l);
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& l) 
{
	if (_head) { delete _head; }
	if (l._head == NULL) { _head = NULL; }
	else { _head = new T((*l._head)); }

	if (_tail) { delete _tail; }
	if (l._tail == NULL) { _tail = NULL; }
	else { _tail = new LinkedList<T>((*l._tail)); }
}

template <typename T>
bool LinkedList<T>::isEmpty() const 
{
	return (_head == NULL);
}

template <typename T>
int LinkedList<T>::length() const 
{
	if (isEmpty()) { // early bail out
		return 0;
	}
	else if (_tail == NULL) { // proper base case
		return 1;
	}
	else { // recursive summation through list elements
		return 1 + (*_tail).length();
	}
}

template <typename T>
T& LinkedList<T>::getContents() 
{
	return (*_head);
}

template <typename T>
void LinkedList<T>::setContents(const T& value) 
{
	(*_head) = value;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getTail()
{
	return _tail;
}

template <typename T>
void LinkedList<T>::append(const T& value)
{
	LinkedList<T> * next = new LinkedList<T>(value);
	next._tail = _tail;
	_tail = next;
}

template <typename T>
void LinkedList<T>::prepend(const T& value)
{
	append((*this));
	if (_head) { delete _head; }
	_head = new T(value);
}

template <typename T>
LinkedList<T> * LinkedList<T>::find(const T& t) {
	if (isEmpty()) { throw new LinkedListMemoryException(); }
	if ((*_head) == t) { return this; }
	else {
		if (_tail) { return tail->find(t); }
		return NULL;
	}
}

template <typename T>
void LinkedList<T>::remove()
{
	LinkedList<T> * temp = new LinkedList<T>((*_tail));
	delete (*this);
	this = temp;
}
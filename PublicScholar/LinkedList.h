/*
Author: Cale Kennedy
Date: 2014 Sep 28
Crediting: Dr. Hougen's CS 2413 Lecture Slides
Description: Base class implementation of array abstract class
*/

#pragma once
#include "AbstractLinkedList.h"

/* Declaration
----------------------------------------------------------------------------- */

template<typename T>
class LinkedList : virtual public AbstractLinkedList<T>
{

protected:
	T* _head;
	LinkedList<T> * _tail;
	void copy(const LinkedList<T>& l);

public:
	// constructors
	LinkedList();
	LinkedList(const T& val);
	LinkedList(const LinkedList<T>& l);

	// destructor 
	virtual ~LinkedList();

	// class methods
	T& operator[] (int k);
	void operator= (const LinkedList<T>& l);

	// length of the entire list
	virtual int length() const;
	// pretty self explanatory
	virtual bool isEmpty();

	// returns contents by value
	virtual T& getContents();

	// sets content of the linked list
	virtual void setContents(const T& t);

	// returns a pointer to the next object in the list
	virtual LinkedList<T>* getTail();

	// adds a node in front of this one
	virtual void prepend(const T& t);

	// adds a node after this one
	virtual void append(const T& t);

	// return a pointer to the first node that passes equality
	virtual LinkedList<T> * find(const T& t);

	// deletes this node, returns its value
	virtual T remove();

};

/* Definition
----------------------------------------------------------------------------- */

template <typename T>
LinkedList<T>::LinkedList()
{
	_head = NULL;
	_tail = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const T& t)
{
	_head = new T(t);
	if (_head == NULL) {
		throw MemoryException();
	}
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
	if (_head != NULL) { 
		delete _head; 
		_head = NULL;
	}
	

	if (_tail != NULL) { 
		delete _tail; 
		_tail = NULL;
	}
	
}

// class methods
template <typename T>
T& LinkedList<T>::operator[] (int k)
{
	// 0 indexed and the last node is a NULL pointer.
	// length() returns the number of elements in the list
	if (k > (length() - 1)) {
		throw OutOfBoundsException();
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
	if (_head != NULL) { delete _head; }
	if (_tail != NULL) { delete _tail; }
	copy(l);
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& l)
{
	
	if (l._head == NULL) { _head = NULL; }
	else {
		_head = new T((*l._head));
		if (_head == NULL) { throw MemoryException(); }
	}

	if (l._tail == NULL) { _tail = NULL; }
	else {
		_tail = new LinkedList<T>((*l._tail));
		if (_tail == NULL) { throw MemoryException(); }
	}
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return (_head == NULL);
}

template <typename T>
int LinkedList<T>::length() const
{
	if (_head == NULL) { // early bail out
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
	if (isEmpty()) {
		throw GetNullContentsException();
	}
	return (*_head);
}

template <typename T>
void LinkedList<T>::setContents(const T& t)
{
	if (_head != NULL) {
		delete _head;
	}
	_head = new T(t);
}

template <typename T>
LinkedList<T>* LinkedList<T>::getTail()
{
	return _tail;
}

template <typename T>
void LinkedList<T>::append(const T& t)
{
	if (isEmpty()) {
		_head = new T(t);
	}
	else {
		LinkedList<T> * next = new LinkedList<T>(t);
		if (next == NULL) { throw MemoryException(); }
		(*next)._tail = _tail;
		_tail = next;
	}
}

template <typename T>
void LinkedList<T>::prepend(const T& t)
{	
	if (isEmpty()) { 
		_head = new T(t); 
	}
	else {
		append((*_head));
		delete _head;
		_head = new T(t);
	}
}

template <typename T>
LinkedList<T> * LinkedList<T>::find(const T& t) {
	if (isEmpty()) { throw MemoryException(); }
	if ((*_head) == t) { return this; }
	else {
		if (_tail != NULL) { return _tail->find(t); }
		else { return NULL; }
	}
}

template <typename T>
T LinkedList<T>::remove()
{
	if (isEmpty()) { throw OutOfBoundsException(); }
	try {
		T retVal = (*_head);
		delete _head;
		if (_tail == NULL) { _head = NULL; }
		else {
			LinkedList<T> * oldTail = _tail;
			_head = _tail->_head;
			_tail = _tail->_tail;
			oldTail->_head = NULL;
			oldTail->_tail = NULL;
		}
		return retVal;
	}
	catch (Exception e) {
		throw MemoryException();
	}

}
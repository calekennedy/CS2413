/*
Author: Cale Kennedy
Date: 2014 Sep 28
Crediting: Wikipedia's abstract class definition (http://en.wikipedia.org/wiki/List_(abstract_data_type)
Description: Abstract class from which all arrays inherit
*/

#pragma once
#include <iostream>
#include "Exception.h"
using namespace std;

//exceptions used by inheritors of Linked List abstract class.
class LinkedListException : public Exception {};
class LinkedListMemoryException : public LinkedListException {};
class LinkedListOutOfBoundsException : public LinkedListException {};

template <typename T>
class AbstractLinkedList
{
public:
	// gets the size of the linked list (counts to last element).
	virtual int length() const = 0;

	// lets us know if the linked list is empty
	virtual bool isEmpty() = 0;

	// getter and setter for the value in the node
	virtual T& getContents() = 0;
	virtual void setContents(const T& value) = 0;

	// returns a pointer to the next node in the Linked List
	virtual AbstractLinkedList<T>* getTail() = 0;

	// adds a node in front of this one
	virtual void prepend(const T& value) = 0;

	// adds a node after this one
	virtual void append(const T& value) = 0;

	virtual AbstractLinkedList<T> * find(const T& t);

	// deletes this node from the list
	virtual void remove() = 0; 
};


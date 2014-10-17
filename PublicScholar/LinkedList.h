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
class LinkedList : virtual public AbstractLinkedList <T>
{

	friend ostream& operator << (ostream& s, LinkedList<T>& l);

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
	~LinkedList();

	// class methods
	T& operator[] (int k);
	void operator= (const LinkedList<T>& l);

	// length of the entire list
	virtual int length() const;
	// pretty self explanatory
	virtual bool isEmpty() const;

	// getter and setter for the value in the node
	virtual T& getContents();
	virtual void setContents(const T& t);

	// returns a pointer to the next object in the list
	virtual LinkedList<T>* getTail();

	// adds a node in front of this one
	virtual void prepend(const T& t);

	// adds a node after this one
	virtual void append(const T& t);

	// return a pointer to the first node that passes equality
	virtual LinkedList<T> * find(const T& t);

	// deletes this node
	virtual void remove();

};
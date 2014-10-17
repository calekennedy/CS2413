/*
Author: Cale Kennedy
Date: 2014 Sep 28
Crediting: Self
Description: Base class implementation of array abstract class
*/

#pragma once
#include "LinkedList.h"

/* Declaration
----------------------------------------------------------------------------- */

template<typename T>
class SortedLinkedList : public LinkedList<T>
{
public:
	SortedLinkedList();
	SortedLinkedList(const T& t);
	SortedLinkedList(const SortedLinkedList<T>& l);

	virtual void add(const T& t);
	virtual void remove(const T& t);
};
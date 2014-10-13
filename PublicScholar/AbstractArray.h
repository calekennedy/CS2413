/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description: Abstract class from which all arrays inherit	
*/

#pragma once
#include <iostream>
#include "Exception.h"
using namespace std;

//exceptions used by inheritors of Array abstract class.
class ArrayException : public Exception {};
class ArrayBoundsException : public ArrayException {};
class ArrayMemoryException : public ArrayException {};

template <typename T>
class AbstractArray
{
public:
	// gets the size of the array.
	virtual int size() const = 0;
	// returns address of kth array element.
	virtual T& operator [] (int k) = 0; 
};


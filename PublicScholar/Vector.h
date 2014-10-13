/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description: Base class implementation of vector abstract class
*/

#pragma once
#include "Array.h"
#include "AbstractVector.h"

/* Declaration
----------------------------------------------------------------------------- */

template <typename T>
class Vector : virtual public Array<T>, virtual public AbstractVector<T>
{
protected:
	int _currSize;
	virtual void setCapacity(int c);
	virtual void increaseCapacity();
	virtual void decreaseCapacity();

public:
	// constructors
	Vector();
	Vector(int n);
	Vector(int n, const T& val);
	Vector(const Vector<T>& v);
	Vector(const Array<T>& a);

	// virtual destructor
	virtual ~Vector();

	void operator= (const Vector<T>& v);
	void operator= (const Array<T>& v);
	virtual T& operator[] (int k);

	virtual void insert(const T& item, int index);
	virtual void remove(int index);
	virtual void add(const T& item);

	virtual int size() const;
	virtual int capacity() const;
};

/* Definition
----------------------------------------------------------------------------- */

template <typename T>
Vector<T>::Vector() : Array<T>()
{
	_currSize = 0;
}

template <typename T>
Vector<T>::Vector(int n) : Array<T>(n)
{
	_currSize = 0;
}

template <typename T>
Vector<T>::Vector(int n, const T& val) : Array<T>(n, val)
{
	_currSize = 0;
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v) : Array<T>(v)
{
	_currSize = v._currSize;
}

template <typename T>
Vector<T>::Vector(const Array<T>& a) : Array<T>(a)
{
	_currSize = a.size();
}

template <typename T>
Vector<T>::~Vector()
{
}

template <typename T>
void Vector<T>::operator= (const Vector<T>& v)
{
	Array<T>::copy(v);
	_currSize = v._currSize;
}

template <typename T>
void Vector<T>::operator= (const Array<T>& a)
{
	Array<T>::copy(a);
	_currSize = a.size();
}

template <typename T>
T& Vector<T>::operator[] (int k)
{
	return Array<T>::operator[] (k);
}

template <typename T>
int Vector<T>::size() const
{
	return _currSize;
}

template <typename T>
int Vector<T>::capacity() const
{
	return _size;
}

// WARNING! This method can truncate data. Use cautiously!!!
template <typename T>
void Vector<T>::setCapacity(int c)
{
	int len = _currSize;
	if (len > c) { len = c; } // we are shrinking the vector, set new length

	T* paNew = new T[c]; // new array with new length
	if (paNew == NULL) 	{ throw ArrayMemoryException(); } // bad initialization

	for (int i = 0; i < len; i++) { 
		paNew[i] = T(paObject[i]); 
	} // add the old data to the new array

	if (paObject != NULL) { delete[] paObject; } // dealloc the old memory

	paObject = paNew; // point at the new array

	_size = c; // set the new size

	if (_currSize > len) { _currSize = len; } // if shrinking change _currSize of vector.
}

template <typename T>
void Vector<T>::increaseCapacity() {
	if ((_currSize + 1) == _size)
	{
		setCapacity((_size * 2));
	}
}

template <typename T>
void Vector<T>::decreaseCapacity() // dynamically shrinks vector by factor of 2 when it is more than half empty
{

	if (_currSize <= (_size / 2))
	{
		setCapacity((_size / 2));
	}
}

template <typename T>
void Vector<T>::add(const T& item)
{
	insert(item, _currSize);
}

template <typename T>
void Vector<T>::insert(const T& item, int index)
{
	if ((index < 0) || (index > _currSize))
	{
		throw ArrayBoundsException();
	}

	increaseCapacity();

	_currSize++;

	for (int i = (_currSize-1); i > index; i--) // right shift all elements from last to index
	{		
		int prev = i - 1;
		T t = (*this).paObject[prev];
		(*this).paObject[i] = t;
	}

	(*this)[index] = item; // insert the new item at the appropriate index

}

template <typename T>
void Vector<T>::remove(int index)
{
	if ((index < 0) || (index >= _currSize))
	{
		throw ArrayBoundsException();
	}

	decreaseCapacity();

	for (int i = index; i < _currSize - 1; i++) // left shift elements from removed element to new end of vector
	{
		(*this)[i] = (*this)[i + 1];
	}
	_currSize--;
}
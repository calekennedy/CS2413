/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description: Base class implementation of array abstract class
*/

#pragma once
#include "AbstractArray.h"

/* Declaration
----------------------------------------------------------------------------- */

template<typename T>
class Array : virtual public AbstractArray<T>
{
	friend ostream& operator << (ostream& s, Array<T>& a);

protected:
	T* paObject;
	int _size;
	void copy(const Array<T>& a);

public:
	// constructors
	Array();
	Array(int n);
	Array(int n, const T& val);
	Array(const Array<T>& a);

	// destructor 
	virtual ~Array();

	// class methods
	int size() const;
	T& operator[] (int k);
	void operator= (const Array<T>& a);
};


/* Definition
----------------------------------------------------------------------------- */

template <typename T>
Array<T>::Array()
{
	_size = 0;
	paObject = new T[1];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = 1;
}

template <typename T>
Array<T>::Array(int n)
{
	_size = 0;
	paObject = new T[n];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = n;
}

template <typename T>
Array<T>::Array(int n, const T& val)
{
	_size = 0;
	paObject = new T[n];
	if (paObject == NULL) throw ArrayMemoryException();
	_size = n;
	for (int i = 0; i < n; i++) {
		paObject[i] = val;
	}
}

template <typename T>
Array<T>::Array(const Array<T>& a)
{
	copy(a);
}

template <typename T>
Array<T>::~Array()
{
	if (paObject != NULL) {
		delete [] paObject;
	}
	paObject = NULL;
	_size = 0;
}

template <typename T>
int Array<T>::size() const
{
	return _size;
}

template <typename T>
T& Array<T>::operator[] (int k)
{
	if ((k < 0) || (k >= size())) {
		throw ArrayBoundsException();
	}
	return paObject[k];
}

template <typename T>
void Array<T>::operator= (const Array<T>& a)
{
	if (paObject != NULL) {
		delete[] paObject;
	}
	copy(a);
}

template <typename T>
ostream& operator << (ostream& s, Array<T>& a)
{
	s << "[";
	for (int i = 0; i < a.size; i++) {
		if (i > 0) {
			s << ',';
		}
		s << a[i];
	}
	s << "]";
	return s;
}

template <typename T>
void Array<T>::copy(const Array<T>& a)
{
	_size = 0; // set to default
	paObject = new T[a._size];
	if (paObject == NULL) {
		throw ArrayMemoryException();
	}
	_size = a._size;
	for (int i = 0; i < _size; i++) {
		paObject[i] = a.paObject[i];
	}
}
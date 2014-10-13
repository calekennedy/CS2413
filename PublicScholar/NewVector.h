/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description: Base class implementation of vector abstract class
*/

#pragma once
#include "Array.h"
#include "AbstractVector.h"

template <class DataType>
class Vector : public virtual Array<DataType>, virtual public AbstractVector<DataType>
{
protected:
	int _currSize;
	void setCapacity(int c);
	void increaseCapacity();
	void decreaseCapacity();

public:
	// constructors
	Vector();
	Vector(int n);
	Vector(int n, DataType& val);
	Vector(const Vector<DataType>& v);
	Vector(const Array<DataType>& a);

	// virtual destructor
	virtual ~Vector();

	void operator= (const Vector<DataType>& v);
	void operator= (const Array<DataType>& v);
	virtual DataType& operator[] (int k);

	void insert(const DataType& item, int index);
	void remove(int index);
	void add(const DataType& item);

	virtual int size() const;
	virtual int capacity() const;
};
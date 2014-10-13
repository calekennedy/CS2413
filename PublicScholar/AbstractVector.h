/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description: Abstract class from which all vectors inherit
*/

#pragma once
template <class DataType>
class AbstractVector : virtual public AbstractArray<DataType>
{
public:
	// insert a new object at the position index in the vector
	virtual void insert(const DataType& item, int index) = 0;
	// remove an object at the position index in the vector
	virtual void remove(int index) = 0;
	// add an object at the end of the vector
	virtual void add(const DataType& item) = 0;
};


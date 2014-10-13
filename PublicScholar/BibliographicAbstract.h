/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Self
	Description: Abstract class from which all Bibliographic classes inherit
*/
#pragma once
#include "String.h"
#include "KeyValuePair.h"

class BibliographicAbstract
{
public:
	virtual String getKey() const = 0; // accessor
	virtual void setKey(const String& key) = 0; // mutator

	virtual String getValue() const = 0; // accessor
	virtual void setValue(const String& key) = 0; // mutator

	virtual void display() = 0; // display

	virtual int size() const = 0; // gets the size of value
};
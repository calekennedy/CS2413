/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Self
	Description: Base class from which all Biliographic classes inherit
*/

#pragma once
#include "BibliographicAbstract.h"
class Bibliographic
{
friend ostream& operator << (ostream& s, const Bibliographic& b);
protected:
	KeyValuePair * _keyValuePair;
	void copy(const Bibliographic& b);
public:
	// constructors
	Bibliographic();
	Bibliographic(const KeyValuePair& kvp);
	Bibliographic(const String& key, const String& value);
	Bibliographic(char * key, char * value);
	Bibliographic(const Bibliographic& b);

	// destructor
	virtual ~Bibliographic(); 

	// accessors
	String getKey() const; 
	String getValue() const; 

	// mutators
	void setKey(const String& newKey);
	void setValue(const String& newValue);

	// display
	void display(); 

	// gets the size of value -- only method that should be overridden by children
	virtual int size();
};


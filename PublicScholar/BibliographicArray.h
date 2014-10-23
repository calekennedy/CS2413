/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description:
		Child of Bibliographic
		Base class for all bibliographic data types that should 
		return an Array of type String when getValue() is called.
					
*/

#pragma once
#include "Bibliographic.h"
class BibliographicArray : virtual public Bibliographic
{
public:
	BibliographicArray();
	BibliographicArray(const KeyValuePair& kvp);
	BibliographicArray(const String& key, const String& value);
	BibliographicArray(char * key, char * value);
	BibliographicArray(const Bibliographic& b);
	virtual ~BibliographicArray();

	// override
	virtual int size();
	// new method
	virtual Vector<String> getValueAsArray() const;
};


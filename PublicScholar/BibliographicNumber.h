/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description:
		Child of Bibliographic
		Base class for all bibliographic data types that should
		return an int when getValue() is called.

*/

#pragma once
#include "Bibliographic.h"
class BibliographicNumber : virtual public Bibliographic
{
public:
	BibliographicNumber();
	BibliographicNumber(const KeyValuePair& kvp);
	BibliographicNumber(const String& key, const String& value);
	BibliographicNumber(char * key, char * value);
	BibliographicNumber(const Bibliographic& b);
	virtual ~BibliographicNumber();

	// new method
	virtual int getValueAsInt() const;
};


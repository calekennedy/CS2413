/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description:
		Child of Bibliographic
		Base class for all bibliographic data types that should
		return a String when getValue() is called.

*/

#pragma once
#include "Bibliographic.h"
class BibliographicString : virtual public Bibliographic
{
public:
	BibliographicString();
	BibliographicString(const KeyValuePair& kvp);
	BibliographicString(const String& key, const String& value);
	BibliographicString(char * key, char * value);
	BibliographicString(const Bibliographic& b);
	virtual ~BibliographicString();
};


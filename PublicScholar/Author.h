#pragma once
#include "BibliographicArray.h"
class Author : virtual public BibliographicArray
{
protected: 
	String _key = String("author");
public:
	// constructors
	Author();
	Author(const KeyValuePair& kvp);
	Author(const String& value);
	Author(char * value);
	Author(const Bibliographic& b);

	//destructor
	virtual ~Author();
};


#pragma once
#include "BibliographicString.h"
class Pages : virtual public BibliographicString
{
protected:
	String _key = String("pages");
public:
	// constructors
	Pages();
	Pages(const KeyValuePair& kvp);
	Pages(const String& value);
	Pages(char * value);
	Pages(const Bibliographic& b);

	//destructor
	virtual ~Pages();
};


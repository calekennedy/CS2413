#pragma once
#include "BibliographicString.h"
class Journal : virtual public BibliographicString
{
protected:
	String _key = String("journal");
public:
	// constructors
	Journal();
	Journal(const KeyValuePair& kvp);
	Journal(const String& value);
	Journal(char * value);
	Journal(const Bibliographic& b);

	//destructor
	virtual ~Journal();
};


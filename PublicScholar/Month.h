#pragma once
#include "BibliographicString.h"
class Month : virtual public BibliographicString
{
protected:
	String _key = String("month");
public:
	// constructors
	Month();
	Month(const KeyValuePair& kvp);
	Month(const String& value);
	Month(char * value);
	Month(const Bibliographic& b);

	//destructor
	virtual ~Month();
};


#pragma once
#include "BibliographicString.h"
class Issn : virtual public BibliographicString
{
protected:
	String _key = String("issn");
public:
	// constructors
	Issn();
	Issn(const KeyValuePair& kvp);
	Issn(const String& value);
	Issn(char * value);
	Issn(const Bibliographic& b);

	//destructor
	virtual ~Issn();
};

